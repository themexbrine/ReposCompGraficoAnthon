#pragma once
#include "Vec3.h"


class Matrix3
{

	float ar[3][3];  ///esto ni de chiste era estatico. cada instancia debe tener sus propios datos
public:


	static Matrix3 rotate(const float& grados)
	{
		//todas las matrices son asi de simples
		float radianes = grados * 3.141592 / 180.0;
				
		Matrix3 mate;
		mate.ar[0][0] = cos(radianes);
		mate.ar[1][0] = -sin(radianes);
		mate.ar[2][0] = 0;
		mate.ar[0][1] = sin(radianes);
		mate.ar[1][1] = cos(radianes);
		mate.ar[2][1] = 0;
		mate.ar[0][2] = 0;
		mate.ar[1][2] = 0;
		mate.ar[2][2] = 1.0;

		return mate;
	}

	static Matrix3 translate(Vec3 a)
	{
		//igual de facil que rotate
		Matrix3 mate;
		mate.ar[0][0] = 1;
		mate.ar[1][0] = 0;
		mate.ar[2][0] = a.x;
		mate.ar[0][1] = 0;
		mate.ar[1][1] = 1;
		mate.ar[2][1] = a.y;
		mate.ar[0][2] = 0;
		mate.ar[1][2] = 0;
		mate.ar[2][2] = 1;
		
		return mate;
	}

	static Matrix3 scale(float x, float y)
	{
		//igual de facil que rotate
		Matrix3 mate;
		mate.ar[0][0] = x;
		mate.ar[1][0] = 0;
		mate.ar[2][0] = 0;
		mate.ar[0][1] = 0;
		mate.ar[1][1] = y;
		mate.ar[2][1] = 0;
		mate.ar[0][2] = 0;
		mate.ar[1][2] = 0;
		mate.ar[2][2] = 1;

		return mate;
	}
	//osera regresarte una matriz para que la  multipliques con otras matrices

	//static Vec3 rotate(Vec3 a, float grados)
	//{
	//	Vec3 res;
	//
	//	//Aqui solo te falta transformar los grados a radianes
	//	float  radianes = grados * 3.141592 / 180.0;
	//	float r[3][3] =
	//	{
	//		{cos(radianes),-sin(radianes),0},
	//		{sin(radianes),cos(radianes),0},
	//		{0,0,1}
	//	};	

	//	
	//	//esto es lo que va en la sobrecarga del operador "*"
	//	res.x = (a.x * r[0][0]) + (a.y * r[1][0]);
	//	res.y = (a.x * r[0][1]) + (a.y * r[1][1]);
	//	
	//	return res;
	//}



	


	//tienes que implementar estas 2 funciones 


	//estas dentro del contexto de la definicion de la clase Matrix3
	//por eso no se usa el Matrix3::operator
	//tampoco deben ser estaticos los operadores
	Matrix3 operator * (const Matrix3& rot)
	{
		Matrix3 res;
		//Aqui ya tienes acceso a los componentes de la matriz 
		
		res.ar[0][0] = (ar[0][0] * rot.ar[0][0] + ar[1][0] * rot.ar[0][1] + ar[2][0] * rot.ar[0][2]); res.ar[1][0] = (ar[0][0] * rot.ar[1][0] + ar[1][0] * rot.ar[1][1] + ar[2][0] * rot.ar[1][2]); res.ar[2][0] = (ar[0][0] * rot.ar[2][0] + ar[1][0] * rot.ar[2][1] + ar[2][0] * rot.ar[2][2]);
		res.ar[0][1] = (ar[0][1] * rot.ar[0][0] + ar[1][1] * rot.ar[0][1] + ar[2][1] * rot.ar[0][2]); res.ar[1][1] = (ar[0][1] * rot.ar[1][0] + ar[1][1] * rot.ar[1][1] + ar[2][1] * rot.ar[1][2]); res.ar[2][1] = (ar[0][1] * rot.ar[2][0] + ar[1][1] * rot.ar[2][1] + ar[2][1] * rot.ar[2][2]);
		res.ar[0][2] = (ar[0][2] * rot.ar[0][0] + ar[1][2] * rot.ar[0][1] + ar[2][2] * rot.ar[0][2]); res.ar[1][2] = (ar[0][2] * rot.ar[1][0] + ar[1][2] * rot.ar[1][1] + ar[2][2] * rot.ar[1][2]); res.ar[2][2] = (ar[0][2] * rot.ar[2][0] + ar[1][2] * rot.ar[2][1] + ar[2][0] * rot.ar[2][2]);

		return res;
	}	//para poder operar matrices * matrices

	//tampoco deben ser estaticos los operadores
	Vec3 operator * (const Vec3& a)
	{
		Vec3 res;
		res.x = (a.x * ar[0][0]) + (a.y * ar[1][0]) + (a.w * ar[2][0]);
		res.y = (a.x * ar[0][1]) + (a.y * ar[1][1]) + (a.w * ar[2][1]);

		return res;
	}//para poder operar matrices * vectores
};

