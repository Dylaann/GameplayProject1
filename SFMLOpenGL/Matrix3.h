#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <Vector3.h>

using namespace std;

class Matrix3new
{// The class has nine variables, 3 rows and 3 columns

	public:

	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;

	// Constructor 1 create a zero matrix
	 Matrix3new::Matrix3new( )
	{
		A11 = 0.0;
		A12 = 0.0;
		A13 = 0.0;
		A21 = 0.0;
		A22 = 0.0;
		A23 = 0.0;
		A31 = 0.0;
		A32 = 0.0;
		A33 = 0.0;
	 }

	// Constructor 2
	 Matrix3new::Matrix3new(Vector3new Row1, Vector3new Row2, Vector3new Row3)
	{  // To allow 3 rows of vectors to be declared as a matrix
		A11 = Row1.x;
		A12 = Row1.y;
		A13 = Row1.z;
		A21 = Row2.x;
		A22 = Row2.y;
		A23 = Row2.z;
		A31 = Row3.x;
		A32 = Row3.y;
		A33 = Row3.z;
	}
	// Constructor 3
	 Matrix3new::Matrix3new(double _A11, double _A12, double _A13,
		double _A21, double _A22, double _A23,
		double _A31, double _A32, double _A33)
	{// to allow nine double values
		A11 = _A11;
		A12 = _A12;
		A13 = _A13;
		A21 = _A21;
		A22 = _A22;
		A23 = _A23;
		A31 = _A31;
		A32 = _A32;
		A33 = _A33;
	}

	 Matrix3new::Vector3new Row(int i)
	 {
		 // a method to return as Row as vector3 0 == first row, default == last row
		 switch (i)
		 {
		 case 0:
			 return Vector3new(A11, A12, A13);
		 case 1:
			 return Vector3new(A21, A22, A23);
		 case 2:
		 default:
			 return Vector3new(A31, A32, A33);
		 }
	 }

	 Matrix3new::Vector3new Column(int i)
	 {// a method to return as column as vector3 0 == first column, default == last column
		 switch (i)
		 {
		 case 0:
			 return Vector3new(A11, A21, A31);
		 case 1:
			 return Vector3new(A12, A22, A32);
		 case 2:
		 default:
			 return Vector3new(A13, A23, A33);
		 }
	 }

	Matrix3new Transpose(Matrix3new M1);
	static double Determinant(Matrix3new M1);
	Matrix3new Inverse(Matrix3new M1);
	Matrix3new Rotation(int _angle);
	Matrix3new Translate(int dx, int dy);
	Matrix3new Scale(int dx, int dy);
	Matrix3new RotationX(int _angle);
	Matrix3new RotationY(int _angle);
	Matrix3new RotationZ(int _angle);
	Matrix3new Scale3D(int dx);

	Vector3new Matrix3new::operator *(Vector3new V1);
	//Vector3new Matrix3new::operator *(Vector3new V1, Matrix3new M1);

};