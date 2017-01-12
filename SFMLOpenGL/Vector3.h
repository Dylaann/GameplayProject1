#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

class Vector3new
{
public:
	// The class has three variables x, y and z 
	double x;
	double y;
	double z;

		// Constructor 1
	Vector3new::Vector3new()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	// Constructor 2
	Vector3new::Vector3new(double x1, double y1, double z1)
	{ // To allow other values for X, Y and Z to be declared
		x = x1;
		y = y1;
		z = z1;
	}
	// Constructor 3
	Vector3new::Vector3new(float x1, float y1, float z1)
	{ // To allow other values for X, Y and Z to be declared
		x = x1;
		y = y1;
		z = z1;
	}

	Vector3new::Vector3new(Vector3new &V1)
	{  // To allow other values for X, Y and Z to be declared
		x = V1.x;
		y = V1.y;
		z = V1.z;
	}


	double Length();
	double LengthSquared(Vector3new V1);
	void Normalise(Vector3new V1);
	Vector3new operator +(Vector3new V1);
	Vector3new operator -(Vector3new V1);
	double operator *(Vector3new V1);

	Vector3new operator *(double k);
	Vector3new operator *(float k);
	Vector3new operator *(int k);
	Vector3new operator ^(Vector3new V1);
};