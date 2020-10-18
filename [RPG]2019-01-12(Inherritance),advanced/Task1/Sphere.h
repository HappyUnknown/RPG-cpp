#pragma once
#include "Shape.h"
class Sphere : public Shape
{
	int radius;
public:
	Sphere();
	Sphere(int radius=0);
	void Print()override;
	void PrintShapeName()override;
	int Area()override;
	int Volume()override;
	~Sphere();
};