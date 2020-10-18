#include <iostream>
using namespace std;
#include "Sphere.h"
Sphere::Sphere()
{
	radius = 0;
}
Sphere::Sphere(int radius)
{
	this->radius = radius;
}
void Sphere::Print()
{
	cout << "Radius : " << radius << endl;
}
void Sphere::PrintShapeName()
{
	cout << "\nSPHERE\n";
}
int Sphere::Area()
{
	cout << "Area = " << 3.1415*(radius*radius) << endl;
	return 0;
}
int Sphere::Volume()
{
	cout << "Volume = " << 4 / 3 * 3.1415 * (radius*radius*radius) << endl;
	return 0;
}

Sphere::~Sphere()
{
	cout << "Hello sphere destructor";
}
