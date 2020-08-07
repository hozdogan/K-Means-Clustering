#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include"Üst Bilgi.h"
using namespace std;


Point2D* Sets::getPoint(int index)
{
	return points.at(index);
}

void Sets::setPoints(Point2D* p, int index)
{
	points[index] = p;
}

void Sets::pb_point(Point2D* p)
{
	points.push_back(p);
}
int Sets::getPointVecLength()
{
	return points.size();
}

void Sets::setMidpoint(Point2D* p)
{
	this->mp = p;
}

Point2D* Sets::getMidPoint()
{
	return this->mp;
}
Point2D* Sets::getTempMidPoint()
{
	return this->tempmp;
}//aðýrlýk merkezleri
void Sets::setTempMidPoint(Point2D* p)
{
	this->tempmp = p;
}

Point2D* Sets::getCenterPoint(int index)
{
	return Centers[index];
}
void Sets::pb_cpoint(Point2D* p)
{
	Centers.push_back(p);
}
void Sets::clearall()
{
	points.clear();
}



//classifiers class

double ClassifiersProcess::BTPLen(Point2D* p1, Point2D* p2)
{
	double res = pow(p2->getX() - p1->getX(), 2) + pow(p2->getY() - p2->getX(), 2);
	return sqrt(res);
}
Point2D* ClassifiersProcess::CGCenter(std::vector<Point2D*> vec, int cid)
{
	int sumX = 0;
	int sumY = 0;
	int count = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->getClassID() == cid)
		{
			sumX += vec[i]->getX();
			sumY += vec[i]->getY();
			count++;
		}
	}
	Point2D* p = new Point2D();
	p->setClassID(cid);
	p->setPoints(sumX / count, sumY / count);//vec.size a bölünce olmaz nokta kadar bölmen lazým yoksa ortaya toplanýr
	return p;
}
float ClassifiersProcess::findMax(double* arr, int size)
{
	double max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;

}
float ClassifiersProcess::findMin(double* arr, int size)
{
	double min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;

}
//override
int ClassifiersProcess::findMinIndex(double* arr, int size)
{
	double min = arr[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
			
	}
	return index;

}

int ClassifiersProcess::findMaxIndex(double* arr, int size)
{
	double max = arr[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
			
	}
	return index;

}

float ClassifiersProcess::s_sapma(double* arr, int size)
{
	float sum = 0.0f,Mean,variance,sumvariance = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	Mean = sum / size;
	for (int i = 0; i < size; i++)
	{
		sumvariance += pow((arr[i] - Mean),2);
	}
	return sqrt(sumvariance / size);

}
float* ClassifiersProcess::normalization(double* arr, int size)
{
	float* newbuf = new float[size];
	float sapma = this->s_sapma(arr, size);
	float Mean,sum = 0.0f;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	Mean = sum / size;
	for (int i = 0; i < size; i++)
	{
		newbuf[i] = (arr[i] - Mean) / sapma;
	}
	return newbuf;
}//verilen dizinin normalize halini döndürür

//point class

void Point2D::setPoints(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Point2D::getX()
{
	return this->x;
}
int Point2D::getY()
{
	return this->y;
}
void Point2D::setX(int x)
{
	this->x = x;
}
void Point2D::setY(int y)
{
	this->y = y;
}
int Point2D::getClassID()
{
	return cid;
}
void Point2D::setClassID(int cid)
{
	this->cid = cid;
}
