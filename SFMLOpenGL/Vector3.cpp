#include "Vector3.h"

double Vector3new::Length()
{  // A method to return the length of the vector
	return (double)sqrt(x * x + y * y + z * z);
}

double Vector3new::LengthSquared(Vector3new V1)
{  // A method to return the length squared of the vector
	return (V1.x * V1.x + V1.y * V1.y + V1.z * V1.z);
}

void Vector3new::Normalise(Vector3new V1)
{  // A method to reduce the length of the vector to 1.0 
   // keeping the direction the same
	if (Length() > 0.0)
	{  // Check for divide by zero
		double magnit = Length();
		V1.x /= magnit;
		V1.y /= magnit;
		V1.z /= magnit;
	}
}


Vector3new Vector3new::operator +(Vector3new V1)
{  // An overloaded operator + to return the sum of 2 vectors
	return Vector3new(V1.x + x, V1.y + y, V1.z + z);
}

Vector3new Vector3new::operator -(Vector3new V1)
{ // An overloaded operator - to return the difference of 2 vectors
	return Vector3new(V1.x - x, V1.y - y, V1.z - z);
}

double Vector3new::operator *(Vector3new V1)
{// An overloaded operator * to return the scalar product of 2 vectors
	return (V1.x * x + V1.y * y + V1.z * z);
}

Vector3new Vector3new::operator *(double k)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3new(x * (float)k, y * (float)k, z * (float)k);
}

Vector3new Vector3new::operator *(float k)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3new(x * k, y * k, z * k);
}

Vector3new Vector3new::operator *(int k)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3new(x * k, y * k, z * k);
}

Vector3new Vector3new::operator ^(Vector3new V1)
{// An overloaded operator ^ to return the vector product of 2 vectors
	return Vector3new(V1.y * z - V1.z * y, V1.z * x - V1.x * z, V1.x * y - V1.y * x);
}
