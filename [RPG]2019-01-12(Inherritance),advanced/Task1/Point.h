#pragma once
#include "Shape.h"
class Point : public Shape
{
	int length;
	int height;
	int width;
public:
	Point();
	Point(int length, int height, int width);
	void Print()override;
	void PrintShapeName()override;
	int Area()override;
	int Volume()override;
	~Point();
};