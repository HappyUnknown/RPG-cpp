#include "Point.h"
#include <iostream>
using namespace std;
Point::Point()
{
	length = 0;
	height = 0;
	width = 0;
}
Point::Point(int length,int height,int width)
{
	this->length = length;
	this->height = height;
	this->width = width;
}
void Point::Print()
{
	cout << "Length : " << length << endl;
	cout << "Height : " << height << endl;
	cout << "Width : " << width << endl;
}
void Point::PrintShapeName()
{
	cout << "\nPOINT\n";
}
int Point::Area()
{
	cout << "Area = 0\n";
	return 0;
}
int Point::Volume()
{
	cout << "Volume = 0\n";
	return 0;
}

Point::~Point()
{
	cout << "\nHello point destructor\n";
}
