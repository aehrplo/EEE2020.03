#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;

typedef struct {
	uint8 dummy[2];
	uint8 bfType[2];
	uint32 bfSize;
	uint16 bfReserved[2];
	uint32 bfOffBits;
} BMPFileHeader;

typedef struct {
	uint32 biSize;
	int32 biWidth;
	int32 biHeight;
	uint16 biPlanes;
	uint16 biBitCount;
	uint32 biCompression;
	uint32 biSizeImage;
	int32 biXPelsPerMeter;
	int32 biYPelsPerMeter;
	uint32 biClrUsed;
	uint32 biClrImportant;
}BMPInfoHeader;
typedef struct {
	BMPFileHeader fileHeader;
	BMPInfoHeader infoHeader;
} BMPHeader;
typedef struct {
	uint8 b;
	uint8 g;
	uint8 r;
} Pixel;

Pixel** create_pixels_2D(int height, int width) {
	// ################ problem 3-1 #####################
	Pixel** pixels = new Pixel*[width];
	for(int x=0; x < width; x++){
		pixels[x] = new Pixel[height];
	}

	return pixels;
	// ################ problem 3-1  ####################
}

class BMPImage {
public:
	BMPHeader header;
	Pixel** pixels;
	Pixel** buffer;
	int height;
	int width;

	BMPImage() {
		this->height = 0;
		this->width = 0;
		this->pixels = NULL;
		this->buffer = NULL;
		set_header("dummy.bmp");
	}
	~BMPImage() {}

	void create_empty_pixels(int height, int width) {
		this->height = height;
		this->width = width;
		this->pixels = create_pixels_2D(height, width);
		set_header("dummy.bmp");
		cout << "create empty_pixel" << endl;
	}
	int create_empty_buffer(int height, int width) {
		if (this->pixels == NULL) {
			cout << "'pixels' is NULL. Cannot Create 'buffer'." << endl;
			this->width = 0;
			this->height = 0;
			return 1;
		}
		else if (this->height == 0 || this->width == 0) {
			cout << "No Width/Height Data." << endl;
			cout << "Class Crushed. Set pixels, width, height to default values NULL, 0, 0" << endl;
			cout << "Cannot conduct memory releasing. Memory leaking might happened." << endl;
			delete[] this->pixels;
			this->pixels = NULL;
			this->width = 0;
			this->height = 0;

			return 2;
		}
		else {
			if (this->buffer != NULL) {
				for (int i = 0; i < this->height; i++) {
					delete[] this->buffer[i];
				}
				delete[] this->buffer;
				this->buffer = NULL;
			}
			this->buffer = create_pixels_2D(height, width);

			return 0;
		}
	}

	int apply_buffer_to_pixels() {
		if (this->pixels != NULL) {
			if (this->width == 0 || this->height == 0) {
				cout << "No Width/Height Data." << endl;
				cout << "Class Crushed. Set pixels, width, height to default values NULL, 0, 0" << endl;
				cout << "Cannot conduct memory releasing. Memory leaking might happened." << endl;
				delete[] this->pixels;
				this->pixels = NULL;
				this->width = 0;
				this->height = 0;
			}
			else {
				for (int h = 0; h < this->height; h++) {
					delete[] this->pixels[h];
				}
				delete[] this->pixels;
				this->pixels = NULL;
			}
		}
		this->pixels = this->buffer;
		this->buffer = NULL;

		return 0;
	}

	int load_bmp_image(const char* fName) {
		if (this->pixels != NULL) {
			for (int h = 0; h < this->height; h++) {
				delete[] this->pixels[h];
			}
			delete[] this->pixels;
			this->pixels = NULL;
		}

		FILE* file = fopen(fName, "rb");
		fread(&(this->header.fileHeader.bfType[0]), sizeof(uint8), 54, file);
		int width = this->header.infoHeader.biWidth;
		int height = this->header.infoHeader.biHeight;
		int numPadding = (4 - ((width * 3) % 4)) % 4;
		uint8 dummy[4];
		this->pixels = create_pixels_2D(height, width);
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				fread(&this->pixels[h][w], sizeof(uint8), 3, file);
			}
			fread(dummy, sizeof(uint8), numPadding, file);
		}
		this->width = width;
		this->height = height;
		set_header("dummy.bmp");
		cout << "BMP File Successfully Loaded. < " << fName << " >" << endl;
		return 0;
	}
	int save_bmp_image(const char* fName) {
		if (this->pixels == NULL) {
			cout << "No Pixel Data. Cannot save bmp image <" << fName << ">." << endl;
			this->width = 0;
			this->height = 0;

			return 1;
		}
		else {
			if (this->height == 0 || this->width == 0) {
				cout << "No Width/Height Data. Cannot save bmp image <" << fName << ">." << endl;
				cout << "Class Crushed. Set pixels, width, height to default values NULL, 0, 0" << endl;
				cout << "Cannot conduct memory releasing. Memory leaking might happened." << endl;
				delete[] this->pixels;
				this->pixels = NULL;
				this->width = 0;
				this->height = 0;

				return 2;
			}
			else {
				int numPadding = (4 - ((this->width * 3) % 4)) % 4;
				uint8 dummy[4] = { 0 };
				this->header.infoHeader.biSizeImage = (this->width * 3 + numPadding) * this->height;
				this->header.fileHeader.bfSize = this->header.infoHeader.biSizeImage + 54;
				this->header.infoHeader.biWidth = this->width;
				this->header.infoHeader.biHeight = this->height;

				FILE* file = fopen(fName, "wb");
				fwrite(&this->header.fileHeader.bfType[0], sizeof(uint8), 54, file);
				for (int h = 0; h < height; h++) {
					for (int w = 0; w < width; w++) {
						fwrite(&(pixels[h][w]), sizeof(uint8), 3, file);
					}
					fwrite(dummy, sizeof(uint8), numPadding, file);
				}
				fclose(file);
				cout << "BMP File Successfully Generated. < " << fName << " >" << endl;

				return 0;
			}
		}
	}

	int set_header(const char* fName) {
		FILE* file = fopen(fName, "rb");
		fread(&(this->header.fileHeader.bfType[0]), sizeof(uint8), 54, file);
		fclose(file);

		int numPadding = (4 - ((this->width * 3) % 4)) % 4;
		this->header.infoHeader.biWidth = this->width;
		this->header.infoHeader.biHeight = this->height;
		this->header.infoHeader.biSizeImage = (width * 3 + numPadding) * height;
		this->header.fileHeader.bfSize = this->header.infoHeader.biSizeImage + 54;

		return 0;
	}
};


int gray_scale(BMPImage* imageClass) {
	imageClass->create_empty_buffer(imageClass->height, imageClass->width);
	// ################ problem3-2 #####################
	for (int h = 0; h < imageClass->height; h++) {
			for (int w = 0; w < imageClass->width; w++) {
				Pixel p = imageClass->pixels[h][w];
				uint8 grey = p.b*0.0722+p.r*0.2126+p.g*0.7152;
				imageClass->buffer[h][w] = {grey, grey, grey};
			}
		}

	// ################ problem3-2 #####################
	imageClass->apply_buffer_to_pixels();
	return 0;
}


int main() {
	BMPImage original_img, gray;

	gray.load_bmp_image("test.bmp");
	gray_scale(&gray);
	gray.save_bmp_image("gray_result.bmp");

	return 0;
}


