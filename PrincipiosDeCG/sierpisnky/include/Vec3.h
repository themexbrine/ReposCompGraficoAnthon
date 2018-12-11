#pragma once

class Vec3
{

public: 
	float x, y, w;
	//construsctor default
	Vec3() : x(0), y(0), w(1)
	{}

	//construtor paraetrizdo
	Vec3(float X, float Y) : x(X), y(Y), w(1)
	{}



};
//Vec3 v; // ejecuta el constructor default
//Vec3 v1(1,2) // ejecuta constructor parametriado