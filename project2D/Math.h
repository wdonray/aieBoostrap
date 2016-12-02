#pragma once
#include <iostream>
class Vector2
{
public:
	//Default constructor
	Vector2() {};
	//Constructor that takes in floats that are set to equal points in the array
	Vector2(float xpos, float ypos) : x(xpos), y(ypos)
	{
		VA[0] = xpos;
		VA[1] = ypos;
	}
	//Name: operator ==
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns a check if each point is equal to the set one
	bool operator == (const Vector2 &A)
	{
		return x == A.x && y == A.y;
	}
	//Name: operator +
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and adds each 
	//point to the other and returns that Vector
	Vector2 operator +(const Vector2 &A)
	{
		Vector2 tmp = Vector2(x + A.x, y + A.y);
		return tmp;
	}
	//Name: operator -
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and subtracts each 
	//point to the other and returns that Vector
	Vector2 operator -(const Vector2 &A)
	{
		Vector2 tmp = Vector2(x - A.x, y - A.y);
		return tmp;
	}
	//Name: operator *
	//Arguments: Takes in a variable called "Mult" with type float
	//Description: Creates a temporary Vector that takes the Vector in the arguments and multiplies each 
	//point to the number that is taken in and returns that Vector
	Vector2 operator *(float Mult)
	{
		Vector2 tmp = Vector2(x * Mult, y * Mult);
		return tmp;
	}
	//Name: Magnitude
	//Arguments: N/A
	//Description: Multplies each point times itself then adds each number up and square roots the whole thing
	float Magnitude()
	{
		return sqrt((x*x) + (y*y));
	}
	//Name: Normalize 
	//Arguments: N/A
	//Description: Creates a temporary vector that dives each point by the Magnitude function then returns that Vector
	Vector2 Normalize()
	{
		Vector2 tmp = Vector2(x / Magnitude(), y / Magnitude());
		return tmp;
	}
	//Name: DotProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns each point times the taken in Vector and adds each of those numbers 
	float DotProduct(const Vector2 &A)
	{
		return (x * A.x) + (y * A.y);
	}
	float VA[2];
	float x, y;
};

class Vector3
{
public:
	//Default constructor
	Vector3() {};
	//Constructor that takes in floats that are set to equal points in the array
	Vector3(float xpos, float ypos, float zpos) : x(xpos), y(ypos), z(zpos)
	{
		VA[0] = xpos;
		VA[1] = ypos;
		VA[2] = zpos;
	}
	//Name: operator ==
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns a check if each point is equal to the set one
	bool operator == (const Vector3 &A)
	{
		return x == A.x && y == A.y && z == A.z;
	}
	//Name: operator +
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and adds each 
	//point to the other and returns that Vector
	Vector3 operator +(const Vector3 &A)
	{
		Vector3 tmp = Vector3(x + A.x, y + A.y, z + A.z);
		return tmp;
	}
	//Name: operator -
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and subtracts each 
	//point to the other and returns that Vector
	Vector3 operator -(const Vector3 &A)
	{
		Vector3 tmp = Vector3(x - A.x, y - A.y, z - A.z);
		return tmp;
	}
	//Name: operator *
	//Arguments: Takes in a variable called "Mult" with type float
	//Description: Creates a temporary Vector that takes the Vector in the arguments and multiplies each 
	//point to the number that is taken in and returns that Vector
	Vector3 operator *(float Mult)
	{
		Vector3 tmp = Vector3(x * Mult, y * Mult, z *Mult);
		return tmp;
	}
	//Name: Magnitude
	//Arguments: N/A
	//Description: Multplies each point times itself then adds each number up and square roots the whole thing
	float Magnitude()
	{
		return sqrt((x*x) + (y*y) + (z*z));
	}
	//Name: Normalize 
	//Arguments: N/A
	//Description: Creates a temporary vector that dives each point by the Magnitude function then returns that Vector
	Vector3 Normalize()
	{
		Vector3 tmp = Vector3(x / Magnitude(), y / Magnitude(), z / Magnitude());
		return tmp;
	}
	//Name: DotProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns each point times the taken in Vector and adds each of those numbers 
	float DotProduct(const Vector3 &A)
	{
		return (x * A.x) + (y * A.y) + (z * A.z);
	}
	//Name: CrossProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary vector that values are given by the cross product
	Vector3 CrossProduct(const Vector3 &A)
	{
		Vector3 tmp = Vector3(y*A.z - z*A.y, x*A.z - z*A.x, z*A.y - z*A.x);
		return tmp;
	}
	float VA[3];
	float x, y, z;
};

class Vector4
{
public:
	//Default constructor
	Vector4() {};
	//Constructor that takes in floats that are set to equal points in the array
	Vector4(float xpos, float ypos, float zpos, float wpos) : x(xpos), y(ypos), z(zpos), w(wpos)
	{
		VA[0] = xpos;
		VA[1] = ypos;
		VA[2] = zpos;
		VA[3] = wpos;
	}
	//Name: operator ==
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns a check if each point is equal to the set one
	bool operator == (const Vector4 &A)
	{
		return x == A.x && y == A.y && z == A.z && w == A.w;
	}
	//Name: operator +
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and adds each 
	//point to the other and returns that Vector
	Vector4 operator +(const Vector4 &A)
	{
		Vector4 tmp = Vector4(x + A.x, y + A.y, z + A.z, w + A.w);
		return tmp;
	}
	//Name: operator -
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and subtracts each 
	//point to the other and returns that Vector
	Vector4 operator -(const Vector4 &A)
	{
		Vector4 tmp = Vector4(x - A.x, y - A.y, z - A.z, w - A.w);
		return tmp;
	}
	//Name: operator *
	//Arguments: Takes in a variable called "Mult" with type float
	//Description: Creates a temporary Vector that takes the Vector in the arguments and multiplies each 
	//point to the number that is taken in and returns that Vector
	Vector4 operator *(float Mult)
	{
		Vector4 tmp = Vector4(x * Mult, y * Mult, z *Mult, w *Mult);
		return tmp;
	}
	//Name: Magnitude
	//Arguments: N/A
	//Description: Multplies each point times itself then adds each number up and square roots the whole thing
	float Magnitude()
	{
		return sqrt((x*x) + (y*y) + (z*z) + (w*w));
	}
	//Name: Normalize 
	//Arguments: N/A
	//Description: Creates a temporary vector that dives each point by the Magnitude function then returns that Vector
	Vector4 Normalize()
	{
		Vector4 tmp = Vector4(x / Magnitude(), y / Magnitude(), z / Magnitude(), w / Magnitude());
		return tmp;
	}
	//Name: DotProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns each point times the taken in Vector and adds each of those numbers 
	float DotProduct(const Vector4 &A)
	{
		return (x * A.x) + (y * A.y) + (z * A.z) + (w * A.w);
	}
	float VA[4];
	float x, y, z, w;
};

class Matrix2
{
public:
	//Default constructor
	Matrix2() {};
	//Constructor that takes a 2x2 array
	Matrix2(float a[2][2])
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				matrix2[i][j] = a[i][j];
			}
		}
	}
	//Constructor that takes in floats to initialize the 2x2 array
	Matrix2(float a, float b, float c, float d) {
		matrix2[0][0] = a;
		matrix2[0][1] = b;
		matrix2[1][0] = c;
		matrix2[1][1] = d;
	}
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 2x2 Matrix
	//Description: Creates a temporary Matrix that holds each equation that will equal that number at that current point
	//then returns that matrix
	Matrix2 operator * (const Matrix2 &a)
	{
		Matrix2 tmp = Matrix2
		(
			matrix2[0][0] * a.matrix2[0][0] + matrix2[0][1] * a.matrix2[1][0],
			matrix2[0][0] * a.matrix2[0][1] + matrix2[0][1] * a.matrix2[1][1],
			matrix2[1][0] * a.matrix2[0][0] + matrix2[1][1] * a.matrix2[1][0],
			matrix2[1][0] * a.matrix2[0][1] + matrix2[1][1] * a.matrix2[1][1]
		);
		return tmp;
	}
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 2x2 Matrix
	//Description: Creates a temporary Vector that holds each equation that will equal that number at that current point
	//then returns that vector
	Vector2 operator * (const Vector2 &a)
	{
		Vector2 tmp = Vector2
		(
			a.x*matrix2[0][0] + a.y*matrix2[1][0], 
			a.x*matrix2[0][1] + a.y*matrix2[1][1]
		);
		return tmp;
	}
	float matrix2[2][2];
};

class Matrix3
{
public:
	//Default constructor
	Matrix3() {};
	//Constructor that takes a 1D array
	Matrix3(float a[9])
	{
		for (int i = 0; i < 3; i++)
		{
			matrix3[i] = a[i];
		}
	}
	//Constructor that takes in floats to initialize the 1D array
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
	{
		matrix3[0] = a;
		matrix3[1] = b;
		matrix3[2] = c;
		matrix3[3] = d;
		matrix3[4] = e;
		matrix3[5] = f;
		matrix3[6] = g;
		matrix3[7] = h;
		matrix3[8] = i;
	}
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 3x3 Matrix
	//Description: Creates floats for each indivdual point in a 3x3 matrix equal to each equation that will get the number
	//at the current point then sets a temporary matrix that has each float and returns it
	Matrix3 operator * (const Matrix3 &a)
	{
		float p1 = (matrix3[0] * a.matrix3[0]) + (matrix3[1] * a.matrix3[3]) + (matrix3[2] * a.matrix3[6]);
		float p2 = (matrix3[0] * a.matrix3[1]) + (matrix3[1] * a.matrix3[4]) + (matrix3[2] * a.matrix3[7]);
		float p3 = (matrix3[0] * a.matrix3[2]) + (matrix3[1] * a.matrix3[5]) + (matrix3[2] * a.matrix3[8]);

		float p4 = (matrix3[3] * a.matrix3[0]) + (matrix3[4] * a.matrix3[3]) + (matrix3[5] * a.matrix3[6]);
		float p5 = (matrix3[3] * a.matrix3[1]) + (matrix3[4] * a.matrix3[4]) + (matrix3[5] * a.matrix3[7]);
		float p6 = (matrix3[3] * a.matrix3[2]) + (matrix3[4] * a.matrix3[5]) + (matrix3[5] * a.matrix3[8]);

		float p7 = (matrix3[6] * a.matrix3[0]) + (matrix3[0] * a.matrix3[3]) + (matrix3[8] * a.matrix3[6]);
		float p8 = (matrix3[6] * a.matrix3[1]) + (matrix3[1] * a.matrix3[4]) + (matrix3[8] * a.matrix3[7]);
		float p9 = (matrix3[6] * a.matrix3[2]) + (matrix3[2] * a.matrix3[5]) + (matrix3[8] * a.matrix3[8]);
		Matrix3 tmp = Matrix3(p1, p2, p3, p4, p5, p6, p7, p8, p9);
		return tmp;
	}
	//Name: Overloading the multiplication operator for vector multiplication
	//Arguments: One argument that takes in a 4D Vector 
	//Description: Creates 3 floats that will has equations that will equal each X, Y, and Z.
	//Then creates a temporay Vector thas holds each float and returns that Vector
	Vector3 operator * (const Vector3 &a)
	{
		float x = (matrix3[0] * a.x) + (matrix3[3] * a.y) + (matrix3[6] * a.z);
		float y = (matrix3[1] * a.x) + (matrix3[4] * a.y) + (matrix3[7] * a.z);
		float z = (matrix3[2] * a.x) + (matrix3[5] * a.y) + (matrix3[8] * a.z);
		Vector3 tmp = Vector3(x, y, z);
		return tmp;
	}
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the X axis for 3D using the
	//overloading operator returning the current instance 
	Matrix3 setRotateX(float a)
	{
		Matrix3 RotateX = Matrix3
		(
			1, 0, 0,
			0, cos(a), -sin(a),
			0, sin(a), cos(a)
		);
		*this = RotateX**this;
		return *this;
	}
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Y axis for 3D using the
	//overloading operator returning the current instance 
	Matrix3 setRotateY(float a)
	{
		Matrix3 RotateY = Matrix3
		(
			cos(a), 0, sin(a), 
			0, 1, 0, 
			-sin(a), 0, cos(a)
		);
		*this = RotateY**this;
		return *this;
	}
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Z axis for 3D using the
	//overloading operator returning the current instance 
	Matrix3 setRotateZ(float a)
	{
		Matrix3 RotateZ = Matrix3
		(
			cos(a), -sin(a), 0, 
			sin(a), cos(a), 0, 
			0, 0, 1
		);
		*this = RotateZ**this;
		return *this;
	}
	float matrix3[9];
};

class Matrix4
{
public:
	//Default constructor
	Matrix4() {};
	//Constructor that takes a 2x2 array
	Matrix4(float a[4][4])
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				matrix4[i][j] = a[i][j];
			}
		}
	}
	//Constructor that takes in floats to initialize the array
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p) {
		matrix4[0][0] = a;
		matrix4[0][1] = b;
		matrix4[0][2] = c;
		matrix4[0][3] = d;
		matrix4[1][0] = e;
		matrix4[1][1] = f;
		matrix4[1][2] = g;
		matrix4[1][3] = h;
		matrix4[2][0] = i;
		matrix4[2][1] = j;
		matrix4[2][2] = k;
		matrix4[2][3] = l;
		matrix4[3][0] = m;
		matrix4[3][1] = n;
		matrix4[3][2] = o;
		matrix4[3][3] = p;
	}
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the X axis for 4D using the
	//overloading operator returning the current instance 
	Matrix4 setRotateX(float a)
	{
		Matrix4 RotateX = Matrix4
		(
			1, 0, 0, 0, 
			0, cos(a), -sin(a), 0, 
			0, sin(a), cos(a), 0, 
			0, 0, 0, 1
		);
		*this = RotateX**this;
		return *this;
	}
	//Name: setRotateY
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Y axis for 4D using the
	//overloading operator returning the current instance 
	Matrix4 setRotateY(float a)
	{
		Matrix4 RotateY = Matrix4
		(
			cos(a), 0, sin(a), 0, 
			0, 1, 0, 0, 
			-sin(a), 0, cos(a), 0, 
			0, 0, 0, 1
		);
		*this = RotateY**this;
		return *this;
	}
	//Name: setRotateZ
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Z axis for 4D using the
	//overloading operator returning the current instance 
	Matrix4 setRotateZ(float a)
	{
		Matrix4 RotateZ = Matrix4
		(
			cos(a), -sin(a), 0, 0, 
			sin(a), cos(a), 0, 0, 
			0, 0, 1, 0, 
			0, 0, 0, 1
		);
		*this = RotateZ**this;
		return *this;
	}
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 4x4 Matrix
	//Description: Creates a temporary matrix that is all zeros then sets them all equal
	//to the two that are multiplied together
	Matrix4 operator * (const Matrix4 &a)const
	{
		Matrix4 tmp = Matrix4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		for (int i = 0; i < 64; i++)
		{
			tmp.matrix4[(i / 16)][(i % 16) / 4] += matrix4[(i / 16)][i % 4] * a.matrix4[i % 4][(i % 16) / 4];
		}
		return tmp;
	}
	//Name: Overloading the multiplication operator for vector multiplication
	//Arguments: One argument that takes in a 4D Vector 
	//Description: Creates a temporary vector that is all zeros loops through the vector
	//and matrix to then multiply each one  
	Vector4 operator * (const Vector4 &a)const
	{
		Vector4 tmp = Vector4(0, 0, 0, 0);
		for (int i = 0; i < 16; i++)
		{
			tmp.VA[i / 4] += matrix4[i % 4][i / 4] * a.VA[i % 4];
		}
		tmp.x = tmp.VA[0];
		tmp.y = tmp.VA[1];
		tmp.z = tmp.VA[2];
		tmp.w = tmp.VA[3];
		return tmp;
	}
	float matrix4[4][4];
};