#pragma once
#include "Shape.h"
class Cylinder :public Shape
{
	int radius;
	int height;
public:
	Cylinder(int height=0,int radius=0);
	Cylinder();
	int Area()override;
	int Volume()override;
	void Print()override;
	void PrintShapeName()override;
	~Cylinder();


};
