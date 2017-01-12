#include "Matrix3.h"

Matrix3new Matrix3new::Transpose(Matrix3new M1)
{// a method to transpose a given matrix
	return Matrix3new(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}


double Matrix3new::Determinant(Matrix3new M1)
{// method to return the determinant of a 3x3 matrix
 //                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}


Matrix3new Matrix3new::Inverse(Matrix3new M1)
{
	// method to return the inverse of a matrix if exists else zero vector
	double det = Determinant(M1);

	if (det == 0)
	{
		return Matrix3new();
	}
	else
	{
		double scale = 1 / det;
		Matrix3new answer = Matrix3new();
		answer.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		answer.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		answer.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		answer.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		answer.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		answer.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		answer.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		answer.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		answer.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return answer;
	}
}

Matrix3new Matrix3new::Rotation(int _angle)
{
	double radians = acos(-1) / 180 * _angle;
	Matrix3new answer = Matrix3new();
	answer.A11 = acos(radians);
	answer.A12 = asin(radians);
	answer.A13 = 0;
	answer.A21 = -asin(radians);
	answer.A22 = acos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}


Matrix3new Matrix3new::Translate(int dx, int dy)
{
	Matrix3new answer = Matrix3new();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = dx;
	answer.A32 = dy;
	answer.A33 = 1;

	return answer;
}

Matrix3new Matrix3new::Scale(int dx, int dy)
{
	Matrix3new answer = Matrix3new();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3new Matrix3new::RotationX(int _angle)
{
	double radians = acos(-1) / 180 * _angle;
	Matrix3new answer = Matrix3new();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = acos(radians);
	answer.A23 = -asin(radians);
	answer.A31 = 0;
	answer.A32 = asin(radians);
	answer.A33 = acos(radians);

	return answer;
}
Matrix3new Matrix3new::RotationY(int _angle)
{
	double radians = acos(-1) / 180 * _angle;
	Matrix3new answer = Matrix3new();
	answer.A11 = acos(radians);
	answer.A12 = 0;
	answer.A13 = asin(radians);
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = -asin(radians);
	answer.A32 = 0;
	answer.A33 = acos(radians);

	return answer;
}

Matrix3new Matrix3new::RotationZ(int _angle)
{
	double radians = acos(-1) / 180 * _angle;
	Matrix3new answer = Matrix3new();
	answer.A11 = acos(radians);
	answer.A12 = -asin(radians);
	answer.A13 = 0;
	answer.A21 = asin(radians);
	answer.A22 = acos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3new Matrix3new::Scale3D(int dx)
{
	Matrix3new answer = Matrix3new();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = (double)dx / 100;

	return answer;
}


Vector3new Matrix3new::operator*(Vector3new V1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return Vector3new(A11 * V1.x + A12 * V1.y + A13 * V1.z,
		A21 * V1.x + A22 * V1.y + A23 * V1.z,
		A31 * V1.x + A32 * V1.y + A33 * V1.z);
}

//Vector3new  Matrix3new::operator *(Vector3new V1, Matrix3new M1)
//{// An overloaded operator * to return the  product of the matrix by a vector
//	return Vector3new(M1.A11 * V1.x + M1.A21 * V1.y + M1.A31 * V1.z,
//		M1.A12 * V1.x + M1.A22 * V1.y + M1.A32 * V1.z,
//		M1.A13 * V1.x + M1.A23 * V1.y + M1.A33 * V1.z);
//}

Matrix3new operator +(Matrix3new M1, Matrix3new M2)
{// An overloaded operator + to return the  sum of two matrix 
	return Matrix3new(M1.A11 + M2.A11, M1.A12 + M2.A12, M1.A13 + M2.A13,
		M1.A21 + M2.A21, M1.A22 + M2.A22, M1.A23 + M2.A23,
		M1.A31 + M2.A31, M1.A32 + M2.A32, M1.A33 + M2.A33);
}
Matrix3new operator -(Matrix3new M1, Matrix3new M2)
{// An overloaded operator * to return the  difference of two matrix
	return Matrix3new(M1.A11 - M2.A11, M1.A12 - M2.A12, M1.A13 - M2.A13,
		M1.A21 - M2.A21, M1.A22 - M2.A22, M1.A23 - M2.A23,
		M1.A31 - M2.A31, M1.A32 - M2.A32, M1.A33 - M2.A33);
}

Matrix3new operator *(double x, Matrix3new M1)
{// An overloaded operator * to return the  product of the matrix by a scalar
	Matrix3new answer = Matrix3new();
	answer.A11 = M1.A11 * x;
	answer.A12 = M1.A12 * x;
	answer.A13 = M1.A13 * x;

	answer.A21 = M1.A21 * x;
	answer.A22 = M1.A22 * x;
	answer.A23 = M1.A23 * x;

	answer.A31 = M1.A31 * x;
	answer.A32 = M1.A32 * x;
	answer.A33 = M1.A33 * x; 

	return answer;
}

Matrix3new operator *(Matrix3new M1, Matrix3new M2)
{// An overloaded operator * to return the  product of two matrix
	Matrix3new answer = Matrix3new();
	answer.A11 = M1.Row(0) * M2.Column(0);
	answer.A12 = M1.Row(0) * M2.Column(1);
	answer.A13 = M1.Row(0) * M2.Column(2);

	answer.A21 = M1.Row(1) * M2.Column(0);
	answer.A22 = M1.Row(1) * M2.Column(1);
	answer.A23 = M1.Row(1) * M2.Column(2);

	answer.A31 = M1.Row(2) * M2.Column(0);
	answer.A32 = M1.Row(2) * M2.Column(1);
	answer.A33 = M1.Row(2) * M2.Column(2);

	return answer;
}

Matrix3new operator -(Matrix3new M1)
{
	return -1 * M1;
}