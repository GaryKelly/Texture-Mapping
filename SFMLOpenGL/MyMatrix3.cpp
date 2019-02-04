#include "MyMatrix3.h"
#include <string>
#pragma once
#define PI           3.14159265358979323846 

//Gary Kelly


/// <summary>
/// Default Constructor
/// </summary>
MyMatrix3::MyMatrix3()
{
	//set initial values to 0
	m_11 = { 0 };
	m_12 = { 0 };
	m_13 = { 0 };
	m_21 = { 0 };
	m_22 = { 0 };
	m_23 = { 0 };
	m_31 = { 0 };
	m_32 = { 0 };
	m_33 = { 0 };
}

/// <summary>
/// constructs matrix with double variables
/// </summary>
/// <param name="t_a11"></param>
/// <param name="t_a12"></param>
/// <param name="t_a13"></param>
/// <param name="t_a21"></param>
/// <param name="t_a22"></param>
/// <param name="t_a23"></param>
/// <param name="t_a31"></param>
/// <param name="t_a32"></param>
/// <param name="t_a33"></param>
MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13,
	double t_a21, double t_a22, double t_a23, 
	double t_a31, double t_a32, double t_a33)
{
	//assigns values to corresponding matrix values
	m_11 = t_a11;
	m_12 = t_a12;
	m_13 = t_a13;
	m_21 = t_a21;
	m_22 = t_a22;
	m_23 = t_a23;
	m_31 = t_a31;
	m_32 = t_a32;
	m_33 = t_a33;
}

/// <summary>
/// Myvector3s passed and assigned to matrix
/// assigns x/y/z coords to corresponding parts of the matrix
/// </summary>
/// <param name="t_row1"></param>
/// <param name="t_row2"></param>
/// <param name="t_row3"></param>
MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3)
{
	//vector 1
	m_11 = t_row1.x;
	m_12 = t_row1.y;
	m_13 = t_row1.z;
	//vector 2
	m_21 = t_row2.x;
	m_22 = t_row2.y;
	m_23 = t_row2.z;
	//vector 3
	m_31 = t_row3.x;
	m_32 = t_row3.y;
	m_33 = t_row3.z;
}


/// <summary>
/// Matrix Deconstructor
/// </summary>
MyMatrix3::~MyMatrix3()
{
}

/// <summary>
/// returns the matrix as a string to output to screen
/// </summary>
/// <returns></returns>
std::string MyMatrix3::toString() const
{
	const std::string output = "[Row 1:" + std::to_string(m_11) + " , " + std::to_string(m_12) + " , " + std::to_string(m_13) + " , "
		+ "Row 2: " + std::to_string(m_21) + " , " + std::to_string(m_22) + " , " + std::to_string(m_23) + " , "
		+ "Row 3: " + std::to_string(m_31) + " , " + std::to_string(m_32) + " , " + std::to_string(m_33) + "]";
	return output;
}

/// <summary>
/// compares matrices and sees if they are equal
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
bool MyMatrix3::operator==(const MyMatrix3 t_other) const
{
	bool equal = false;
	//AND used because all values must be equal in order for the matrices to be equal 
	if (m_11 == t_other.m_11 && m_12 == t_other.m_12 && m_13 == t_other.m_13 && //compare row 1
		m_21 == t_other.m_21 && m_22 == t_other.m_22 && m_23 == t_other.m_23 && //compare row 2
		m_31 == t_other.m_31 && m_32 == t_other.m_32 && m_33 == t_other.m_33)   //compare row 3
	{
		equal = true;
	}
	return equal;
}

/// <summary>
/// compares matrices to see if not equal
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
bool MyMatrix3::operator!=(const MyMatrix3 t_other) const
{
	bool notEqual = false;
	//OR used beacause if one value is not equal then the matrices are not equal
	if (m_11 != t_other.m_11 || m_12 != t_other.m_12 || m_13 != t_other.m_13 || //compare row 1
		m_21 != t_other.m_21 || m_22 != t_other.m_22 || m_23 != t_other.m_23 || //compare row 2
		m_31 != t_other.m_31 || m_32 != t_other.m_32 || m_33 != t_other.m_33)   //compare row 3
	{
		notEqual = true;
	}
	return notEqual;
}

/// <summary>
/// Adds two matrices 
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{
	//row 1
	double mA11 = m_11 + t_other.m_11;
	double mA12 = m_12 + t_other.m_12;
	double mA13 = m_13 + t_other.m_13;
	//row 2 
	double mA21 = m_21 + t_other.m_21;
	double mA22 = m_22 + t_other.m_11;
	double mA23 = m_23 + t_other.m_23;
	//row 3
	double mA31 = m_31 + t_other.m_31;
	double mA32 = m_32 + t_other.m_32;
	double mA33 = m_33 + t_other.m_33;

	//assign new values to matrix.
	MyMatrix3 matrixAdd{ mA11,mA12,mA13,mA21,mA22, mA23, mA31, mA32, mA33 };

	return matrixAdd;
}


/// <summary>
/// subtracts one matrix from another
/// </summary>
/// <param name="t_other"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	//row 1
	double mS11 = m_11 - t_other.m_11;
	double mS12 = m_12 - t_other.m_12;
	double mS13 = m_13 - t_other.m_13;
	//row 2 
	double mS21 = m_21 - t_other.m_21;
	double mS22 = m_22 - t_other.m_11;
	double m_s23 = m_23 - t_other.m_23;
	//row 3
	double mS31 = m_31 - t_other.m_31;
	double mS32 = m_32 - t_other.m_32;
	double mS33 = m_33 - t_other.m_33;

	//assign new values to matrix.
	MyMatrix3 matrixSub{ mS11,mS12,mS13,mS21,mS22, m_s23, mS31, mS32, mS33 };

	return matrixSub;
}


/// <summary>
/// Matrix Multiplication
/// </summary>
/// <param name="t_other"></param>
/// <returns>matrix3</returns>
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	//row 1 
	double mM11 = ((m_11 * t_other.m_11) + (m_12 * t_other.m_21) + (m_13 * t_other.m_31));
	double mM12 = ((m_11 * t_other.m_12) + (m_12 * t_other.m_22) + (m_13 * t_other.m_32));
	double mM13 = ((m_11 * t_other.m_13) + (m_12 * t_other.m_23) + (m_13 * t_other.m_33));
	//row 2
	double mM21 = ((m_21 * t_other.m_11) + (m_22 * t_other.m_21) + (m_23 * t_other.m_31));
	double mM22 = ((m_21 * t_other.m_12) + (m_22 * t_other.m_22) + (m_23 * t_other.m_32));
	double mM23 = ((m_21 * t_other.m_13) + (m_22 * t_other.m_23) + (m_23 * t_other.m_33));
	//row 3
	double mM31 = ((m_31 * t_other.m_11) + (m_32 * t_other.m_21) + (m_33 * t_other.m_31));
	double mM32 = ((m_31 * t_other.m_12) + (m_32 * t_other.m_22) + (m_33 * t_other.m_32));
	double mM33 = ((m_31 * t_other.m_13) + (m_32 * t_other.m_23) + (m_33 * t_other.m_33));

	MyMatrix3 matrixMult{mM11, mM12, mM13, mM21, mM22, mM23, mM31, mM32, mM33};

	return matrixMult;
}


/// <summary>
/// matrix by vector3 multiplication
/// </summary>
/// <param name="t_vector"></param>
/// <returns>3dvector</returns>
MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	double mx = (t_vector.x * m_11) + (t_vector.y * m_21) + (t_vector.z * m_31); //new x coord
	double my = (t_vector.x * m_12) + (t_vector.y * m_22) + (t_vector.z * m_32); //new y coord
	double mz = (t_vector.x * m_13) + (t_vector.y * m_23) + (t_vector.z * m_33); //new z coord 

	MyVector3 matByVect{ mx, my, mz };
	return matByVect;
}


/// <summary>
/// multiplies matrix by a scalar
/// </summary>
/// <param name="t_scale"></param>
/// <returns>matrix3</returns>
MyMatrix3 MyMatrix3::operator*(const double t_scale) const
{
	//row 1
	double mms11 = t_scale * m_11;
	double mms12 = t_scale * m_12;
	double mms13 = t_scale * m_13;
	//row 2
	double mms21 = t_scale * m_21;
	double mms22 = t_scale * m_22;
	double mms23 = t_scale * m_23;
	//row 3
	double mms31 = t_scale * m_31;
	double mms32 = t_scale * m_32;
	double mms33 = t_scale * m_33;

	MyMatrix3 matrixMultScale{mms11, mms12, mms13, mms21, mms22, mms23, mms31, mms32, mms33};
	return matrixMultScale;
}


/// <summary>
/// transposes a matrix
/// </summary>
/// <returns>matrix3</returns>
MyMatrix3 MyMatrix3::transpose() const
{
	//Row 1
	double mT11 = m_11;
	double mT12 = m_21;
	double mT13 = m_31;
	//Row 2
	double mT21 = m_12;
	double mT22 = m_22;
	double mT23 = m_32;
	//Row 3
	double mT31 = m_13;
	double mT32 = m_23;
	double mT33 = m_33;

	MyMatrix3 matrixTranspose{ mT11, mT12, mT13, mT21, mT22, mT23, mT31, mT32, mT33 };
	return matrixTranspose;
}

/// <summary>
/// calculates the determinant of the matrix
/// </summary>
/// <returns></returns>
double MyMatrix3::determinant() const
{
	// I split these into different values for neatness
	double det11 = m_11*((m_22*m_33) - (m_32*m_23)); 
	double det21 = m_21*((m_33*m_12) - (m_32*m_13));
	double det31 = m_31*((m_23*m_12) - (m_22*m_13));

	
	double determinant = det11 - det21 + det31;
	return determinant;
}

/// <summary>
/// Finds the inverse matrix of the passed matrix
/// </summary>
/// <returns></returns>
MyMatrix3 MyMatrix3::inverse() const
{
	MyMatrix3 inverseMat;

	if (determinant() != 0) // insures you never divide by zero
	{
		double detUnder1 = 1 / determinant();
		//row 1
		double mI11 = ((m_33*m_22) - (m_32*m_23));
		double mI12 = ((m_32*m_13) - (m_33*m_12));
		double mI13 = ((m_23*m_12) - (m_22*m_13));
		//row 2
		double mI21 = ((m_31*m_23) - (m_33*m_21));
		double mI22 = ((m_33*m_11) - (m_31*m_13));
		double mI23 = ((m_21*m_13) - (m_23*m_11));
		//row 3
		double mI31 = ((m_32*m_21) - (m_31*m_22));
		double mI32 = ((m_31*m_12) - (m_32*m_11));
		double mI33 = ((m_22*m_11) - (m_21*m_12));

		MyMatrix3 newMatrix{ mI11, mI12, mI13, mI21, mI22, mI23, mI31, mI32, mI33 }; //assign to a matrix
		inverseMat = newMatrix.operator*(detUnder1); //multiply matrix by 1/det
	}
	
	
	return inverseMat;
}

/// <summary>
/// returns a row of the matrix as a 3d vector
/// </summary>
/// <param name="t_row">num 0-2</param>
/// <returns></returns>
MyVector3 MyMatrix3::row(const int t_row) const
{
	MyVector3 vectorForRow;

	switch (t_row) //switch for assigning vector with passed int
	{
	case 0:
		vectorForRow={ m_11, m_12, m_13 };
		break;
	case 1:
		vectorForRow = { m_21, m_22, m_23 };
		break;
	case 2:
		vectorForRow = { m_31, m_32, m_33 };
		break;
	default:
		break;
	}
	return vectorForRow;
}

/// <summary>
/// returns a 3d vector of a column from the matrix
/// </summary>
/// <param name="t_column">number 0-2</param>
/// <returns></returns>
MyVector3 MyMatrix3::column(const int t_column) const
{
	MyVector3 vectorForCol;

	switch (t_column)//switch for assigning vector with passed int
	{
	case 0:
		vectorForCol = { m_11, m_21, m_31 };
		break;
	case 1:
		vectorForCol = { m_12, m_22, m_32 };
		break;
	case 2:
		vectorForCol = { m_13, m_23, m_33 };
		break;
	default:
		break;
	}
	return vectorForCol;
}

/// <summary>
/// Rotaion about the z axis
/// </summary>
/// <param name="t_angleRadians"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{
	MyMatrix3 rotationMatrix = {cos(t_angleRadians), -sin(t_angleRadians), 0, //row 1
								sin(t_angleRadians), cos(t_angleRadians), 0, //row 2
								0,0,1};	//row 3
	
	
	return rotationMatrix;
}

/// <summary>
/// returns rotation matrix
/// </summary>
/// <param name="t_angleRadians"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	MyMatrix3 rotateY = { cos(t_angleRadians), 0, -sin(t_angleRadians),
						  0,1,0,
						  sin(t_angleRadians), 0, cos(t_angleRadians) };
	return rotateY;
}

/// <summary>
/// rotation matrix about x axis
/// </summary>
/// <param name="t_angleRadians"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	MyMatrix3 rotateX{ 1,0,0, //row 1
					  0,cos(t_angleRadians), -sin(t_angleRadians), //row 2
					  0, sin(t_angleRadians) , cos(t_angleRadians) }; //row 3
	return rotateX;
}


/// <summary>
/// returns the matrix to translate 
/// </summary>
/// <param name="t_displacement"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	MyMatrix3 tran{ 1, 0, 0,
				    0, 1, 0,
				    t_displacement.x, t_displacement.y, 0 };
	return tran;
}


/// <summary>
/// returns the matrix scale to mulyiply 
/// </summary>
/// <param name="t_scalingfactor"></param>
/// <returns></returns>
MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	MyMatrix3 scaleMatrix{ t_scalingfactor, 0, 0, //row 1
						  0, t_scalingfactor, 0,  //row 2
						  0, 0, 1 }; //row 3
	return scaleMatrix;
}


