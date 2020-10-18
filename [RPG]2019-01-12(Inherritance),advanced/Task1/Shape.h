#pragma once
class Shape
{
	int width;
	int height;
	int length;
public:
	virtual void Print() = 0;
	virtual void PrintShapeName() = 0;
	virtual int Area() abstract;
	virtual int Volume() abstract;

};