#pragma once
#include "BaseApplication.h"
#include "Vec3.h"

class ej : public BaseApplication
{
	private:
	int centerX, centerY;
	int currentPositionX, currentPositionY;
	int v1 = (rand() % 4) + 3;
	 int v2 = (rand() % 4) + 3;
	 int v3 = (rand() % 4) + 3;
	 int v4 = (rand() % 4) + 3;
	 int v5 = (rand() % 4) + 3;

	Color currentColor;
	
	
public:
	ej();

	~ej();
	virtual void setup();
	virtual void update();
	 void draw();


	virtual void clearScreen();
	virtual void setColor(Color color);
	virtual void moveTo (int x, int y);
	virtual void lineTo (int x, int );
	virtual void lineToVec(Vec3 b);
	virtual void serpinsky(int subdiv ,Vec3 a, Vec3 b, Vec3 c);
	virtual void LineVec(Vec3 a, Vec3 b);
	virtual Vec3 MidVec(Vec3 a, Vec3 b);

	virtual void putDaPixel(const int & x,const int & y);
	virtual void line(int x,  int  y, int xfinal,  int yfinal);
	virtual void triangle(Vec3 a, Vec3 b, Vec3 c );
	virtual void shapeMaker(int lados, int radio);


	/*Color c;*/

	/*int currentPosX;
	int currentPosY;
	int CenterX,CenterY;*/
	

	

};
