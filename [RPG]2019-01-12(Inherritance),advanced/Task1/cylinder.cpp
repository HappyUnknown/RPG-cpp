#include "Cylinder.h"
#include <iostream>
using namespace std;
Cylinder::Cylinder()
{
	this->height = 0;
	this->radius = 0;
}
Cylinder::Cylinder(int height, int radius)
{
	this->height = height;
	this->radius = radius;
}
int Cylinder::Area()
{
	cout << "Area = "<<3.1415*(radius*radius);
	return 0;
}
int Cylinder::Volume()
{
	cout << "Volume = "<< 3.1415*(radius*radius)*height;
	return 0;
}
void Cylinder::Print()
{
	cout << "Height = " << height << endl;
	cout << "Radius = " << radius << endl;

}
void Cylinder::PrintShapeName()
{
	cout << "\nCYLINDER\n";
}

Cylinder::~Cylinder()
{
	cout << "\nHello cylinder destructor\n";
}
