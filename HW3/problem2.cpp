#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

struct coord
{
	int x;
	int y;
};
coord** function1(int column, int row);
void function2(int column, int row, coord** a);
void function3(int column, coord** a);

int main()
{
	int column = 0;
	int row = 0;
	cout << "Enter height of area : ";
	cin >> column;
	cout << "Enter width of area : ";
	cin >> row;
	coord** a = function1(column, row);
	cout << "<Right angle example>" << endl;
	function2(column, row, a);
	cout << "\n" << "<Non right angle example>" << endl;
	function2(column, row, a);
	function3(column, a);
	return 0;
}

coord** function1(int column, int row)
{
	/***************Problem1-1***************/
	coord** a = new coord*[column];
	for (int i = 0; i < column; i++){
		a[i] = new coord[row];
	}
	for (int i = 0; i < column; i++){
		for (int j = 0; j < row; j++){
			a[i][j] = {j, i};
		}
	}

	return a;
	/******************End*******************/
}

void function2(int column, int row, coord** a)
{
	/***************Problem1-2***************/
	auto print_coord = [](coord& a){cout << "(" << a.x << ", " << a.y << ") ";};
	auto distanceSquared = [](coord* p1, coord* p2) -> int { return pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2);};

	for (int i = 0; i < column; i++){
		for (int j = 0; j < row; j++){
			print_coord(a[i][j]);
		}
		cout << endl;
	}
	// coord* b = (coord*)malloc(sizeof(coord)*3);
	coord* b[3];
	cout << "Enter three points : ";
	for(int i = 0; i < 3; i++){
		int x, y;
		cin >> x >> y;
		b[i] = &a[y][x];	// input value x, y가 미리 선언한 2D 좌표 평면 범위에 해당하지 않을 경우에 대해 에러 핸들링 하지 않음.
	}
	// cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> b[2].x >> b[2].y;
	cout << "For Coordinates : ";
	for(int i = 0; i < 3; i++){
		print_coord(*b[i]);
	}
	cout << endl;

	int l[3], high=0;
	l[0]= distanceSquared(b[0], b[1]);
	l[1]= distanceSquared(b[2], b[0]);
	l[2]= distanceSquared(b[1], b[2]);

	for(int i=0; i< 3; i++){
		if(l[i] > high) high = l[i];
	}

	if (high == l[0] + l[1] + l[2] - high)
        cout << "Right angle triangle" << endl;
    else
        cout << "Non right angle triangle" << endl;
	/******************End*******************/
}

void function3(int column, coord** a)
{
	/***************Problem1-3***************/
	for(int i = 0; i < column; i++){
		delete a[i];
	}
	delete a;
	/******************End*******************/
}