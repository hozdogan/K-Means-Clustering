#pragma once
#include<vector>

class Point2D
{
public:
	Point2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point2D() {};
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void setPoints(int, int);
	void setClassID(int cid);
	int getClassID();

private:
	int x, y, cid;

};
class Sets
{
public:
	Point2D* getPoint(int index);
	Point2D* getCenterPoint(int index);
	void pb_cpoint(Point2D* p);
	void setPoints(Point2D*,int index);
	void pb_point(Point2D* p);
	void setMidpoint(Point2D* p);
	void setTempMidPoint(Point2D* p);
	void setDistance(float value,int index);
	double getDistance(int index);
	double* getDistances();
	int getPointVecLength();
	void clearall();
	Point2D* getMidPoint();
	Point2D* getTempMidPoint();//aðýrlýk merkezleri
	Sets() {};

private:
	std::vector<Point2D*> points;
	std::vector<Point2D*> Centers;
	Point2D* mp;
	Point2D* tempmp;
};

class ClassifiersProcess
{
public:
	double BTPLen(Point2D* p1, Point2D* p2);
	Point2D* CGCenter(std::vector<Point2D*> vec, int);
	float findMax(double* arr, int size);
	float findMin(double* arr, int size);//index bulmasý lazým
	float s_sapma(double* arr, int size);
	float* normalization(double* arr, int size);
	int ClassifiersProcess::findMinIndex(double* arr, int size);
	int ClassifiersProcess::findMaxIndex(double* arr, int size);


private:


};

class Renk
{
public:
	Renk(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	int getRed()
	{
		return this->r;
	}
	int getBlue()
	{
		return this->b;
	}
	int getGreen()
	{
		return this->g;
	}
	void setRed(int r)
	{
		this->r = r;
	}
	void setGreen(int g)
	{
		this->g = g;
	}
	void setBlue(int b)
	{
		this->b = b;
	}

private:
	int r, g, b;
};





