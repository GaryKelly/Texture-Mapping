/// <summary>
/// Vector 3 class
/// Gary Kelly

#include "MyVector3.h"
#include <string.h>
#include <iostream>
#include <math.h>
#define PI           3.14159265358979323846

/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}

/// <summary>
/// Constructs the coords of the vector as doubles
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = { t_x };
	y = { t_y };
	z = { t_z };
}


/// <summary>
/// 3D vector coords assigned float data type
/// </summary>
/// <param name="t_sfVector"></param>
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = t_sfVector.x;
	y = t_sfVector.y;
	z = t_sfVector.z;
}

/// <summary>
/// 3D vector coords assigne int data type
/// </summary>
/// <param name="t_sfVector"></param>
MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	z = static_cast<int>(t_sfVector.z);
}


/// <summary>
/// 2D vector coords assigned int data type
/// </summary>
/// <param name="t_sfVector"></param>
MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	// z-coordinate not needed
}

/// <summary>
/// gives a vector with unsinged coords
/// </summary>
/// <param name="t_sfVector"></param>
MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	//if the coords are negative the are made positive so the number stays the same after casting
	if (t_sfVector.x < 0)
	{
		t_sfVector.x *= -1;
	}
	if (t_sfVector.y < 0)
	{
		t_sfVector.y *= -1;
	}
	x = static_cast<unsigned>(t_sfVector.x);
	y = static_cast<unsigned>(t_sfVector.y);
}

/// <summary>
/// assingns float data type to the coords of 2D vector
/// </summary>
/// <param name="t_sfVector"></param>
MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x =  static_cast<float>(t_sfVector.x);
	y = static_cast<float>(t_sfVector.y);
}

/// <summary>
/// check for equality
/// </summary>
/// <param name="t_right"></param>
/// <returns></returns>
bool MyVector3::operator==(const MyVector3 t_right) const
{
	const bool answer{ x == t_right.x && y == t_right.y && z == t_right.z };
	return answer;
}

/// <summary>
/// check for inequality
/// </summary>
/// <param name="t_right"></param>
/// <returns></returns>
bool MyVector3::operator!=(const MyVector3 t_right) const
{
	const bool answer{ x != t_right.x || y != t_right.y || z != t_right.z};
	return answer;
}

/// <summary>
/// addition of coords operator
/// </summary>
/// <param name="t_right"></param>
/// <returns></returns>
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);

}

/// <summary>
/// subtraction of coords operator
/// </summary>
/// <param name="t_right"></param>
/// <returns></returns>
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}

/// <summary>
/// multiplication by a scalar
/// </summary>
/// <param name="t_scalar"></param>
/// <returns></returns>
MyVector3 MyVector3::operator*(const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

/// <summary>
/// division by a divisor 
/// </summary>
/// <param name="t_divisor"></param>
/// <returns></returns>
MyVector3 MyVector3::operator/(const double t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor , z / t_divisor);
}

/// <summary>
/// plus equals operator
/// </summary>
/// <param name="t_right"></param>
/// <returns></returns>
MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;
	return MyVector3(x, y, z);
}

/// <summary>
/// minus equals operator
/// </summary>
/// <param name="t_right"></param>
/// <returns></returns>
MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;
	return MyVector3(x, y, z);
}

/// <summary>
/// make vector negative operator
/// </summary>
/// <returns></returns>
MyVector3 MyVector3::operator-()
{
	x *= -1;
	y *= -1;
	z *= -1;
	return MyVector3(x , y , z);
}

/// <summary>
/// calculating length of vector of 3D vector
/// </summary>
/// <returns></returns>
double MyVector3::length() const
{
	const double length = std::sqrt(x*x + y*y + z*z);
	return length;
}

/// <summary>
/// calculating length squared of 3D vector
/// </summary>
/// <returns></returns>
double MyVector3::lengthSquared() const
{
	double lengthSquared = length()*length();
	return lengthSquared;
}

/// <summary>
/// calculating dot product of two 3D vectors
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
double MyVector3::dot(const MyVector3 t_other) const
{
	const double dot = x * t_other.x + y * t_other.y + z * t_other.z;
	return dot;
}

/// <summary>
/// calculating cross product of two 3D vectors
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	const MyVector3 cross (y*t_other.z - z*t_other.y, z*t_other.x - x*t_other.z, x*t_other.y - y*t_other.x);
	return cross;
}

/// <summary>
/// calculating angle between two 3D vetcors
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
double MyVector3::angleBetween(const MyVector3 t_other) const
{
	double lengthV1 = length();
	double lengthV2 = std::sqrt((pow(t_other.x, 2)) + (pow(t_other.y,2)) + (pow(t_other.z,2)));
	double lengthP = lengthV1*lengthV2;
	double dotP = dot(t_other);
	double angleRad = acos((dotP / lengthP));
	const double angleDeg = angleRad*(180 / PI);
	return angleDeg;
}

/// <summary>
/// calculating unit vector 
/// </summary>
/// <returns></returns>
MyVector3 MyVector3::unit() const
{
	const MyVector3 unit((x / length()), (y / length()), (z / length()));
	return unit;
}

/// <summary>
/// normalising the coords
/// </summary>
void MyVector3::normalise()
{
	x = x / length();
	y = y / length();
	z / z / length();
}

/// <summary>
/// projecting vector onto another
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	double projectionX = x * dot(t_other) / lengthSquared();
	double projectionY = y * dot(t_other) / lengthSquared();
	double projectionZ = z * dot(t_other) / lengthSquared();
	return MyVector3(projectionX,projectionY,projectionZ);
}

/// <summary>
/// rejection of vectors
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	const MyVector3 rejection = (t_other) - projection(t_other);
	return rejection;
}

void MyVector3::reverseX()
{
	x = -x;
}

void MyVector3::reverseY()
{
	y = -y;
}






