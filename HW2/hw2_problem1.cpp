#include<iostream>
using namespace std;
class Person
{
public:
	Person() {}	// Constructor
	~Person() { // Destructor
		delete[] name;
	}
	int getID()
	{
		return ID;
	}
	int getHeight()
	{
		return height;
	}
	char* getName()
	{
		return name;
	}

	//************ problem 1-1, 1-2 *******************//
	void init(int p_id, string p_name, int p_height) {
		ID = p_id;
		height = p_height;
		int nameLength = p_name.length() + 1;
		name = new char[nameLength];
		for (size_t i = 0; i < nameLength; i++) {
			name[i] = p_name[i];
		}
	}

	void printStudentInfo() {
		cout << "ID: " << ID << " name: " << name << " height: " << height << endl;
	}

	//************ problem 1-1, 1-2 *******************//


private:
	int ID;
	int height;
	char* name;

};
//************************ problem 1-1, 1-2 *************************//


//************************ problem 1-1, 1-2 *************************//



void personSwap(Person* a) {
	//************************ problem 1-3 *************************//
	Person* temp = new Person;
	*temp = a[0];
	a[0] = a[1];
	a[1] = *temp;
	//************************ problem 1-3 *************************//
}


int main() {
	Person* p = new Person[2];

	p[0].init(12345678, "my_name", 190);
	p[1].init(87654321, "your_name", 160);

	p[0].printStudentInfo();
	p[1].printStudentInfo();

	personSwap(p);
	cout << "swap value" << endl;
	p[0].printStudentInfo();
	p[0].~Person();
	p[1].printStudentInfo();
	system("pause");


	return 0;
}



