#include <iostream>
#include "Shape.h"
#include "Sphere.h"
#include "Point.h"
#include "Cylinder.h"
using namespace std;
int main()
{
	Shape*arr[2] = { {new Point(2,3,4)},{new Sphere(10)} };
	for (int i = 0; i < 2; i++)
	{
		arr[i]->PrintShapeName();
		arr[i]->Print();
	}

	system("pause");
	return 0;
}