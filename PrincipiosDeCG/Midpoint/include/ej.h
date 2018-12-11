#pragma once
#include "BaseApplication.h"


class ej : public BaseApplication
{
	private:
	int centerX, centerY;
	int currentPositionX, currentPositionY;
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
	virtual void putDaPixel(const int & x,const int & y);
	virtual void line(int x,  int  y, int xfinal,  int yfinal);
	
	virtual void shapeMaker(int lados, int radio);


	/*Color c;*/

	/*int currentPosX;
	int currentPosY;
	int CenterX,CenterY;*/
	

	

};
