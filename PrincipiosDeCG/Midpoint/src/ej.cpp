#include "ej.h"
#include <math.h>

#define _USE_MATH_DEFINES

#include <cmath>

ej::ej() : BaseApplication()
{
	centerX = WIDTH / 2;
	centerY = HEIGHT / 2;
	currentPositionX = 0;
	currentPositionY = 0;
	 
}
		
ej::~ej()
{


}

 void ej::setup()
{}

 void ej::update()
 {}

 void ej::clearScreen()
 {
	 Color eraser(0, 0, 0, 255);

	 for (int i = 0; i < WIDTH; i++)
	 {
		 putPixel(i, 0, eraser);
		 for (int y = 0; y < HEIGHT; i++)
		 {
			 
		 }
	 }
		 
	 

 }

 void ej::line(int X1, int Y1, int X2, int Y2)
 {

	 int ang = 0.0;
	 int _x1 = 0;
	 int _y1 = 0;
	 int _x2 = 0;
	 int _y2 = 0;

	 ang = (atan2(Y2 - Y1, X2 - X1) * (180.0 / 3.1416));

	 if (ang >= 0.0)
	 {
		 if (Y2 < 0)
			 ang = 359;
		 else
			 ang = ang;
	 }

	 else if (ang < 0.0)
	 {
		 ang = 360.0 + ang;
	 }

	 if (ang >= 45 && ang < 90)
	 {
		 _x1 = Y1;
		 _y1 = X1;
		 _x2 = Y2;
		 _y2 = X2;
	 }

	 else if (ang >= 90 && ang < 135)
	 {
		 _x1 = Y1;
		 _y1 = -X1;
		 _x2 = Y2;
		 _y2 = -X2;
	 }

	 else if (ang >= 135 && ang < 180)
	 {
		 _x1 = -X1;
		 _y1 = Y1;
		 _x2 = -X2;
		 _y2 = Y2;
	 }

	 else if (ang >= 180 && ang <= 225)
	 {
		 _x1 = -X1;
		 _y1 = -Y1;
		 _x2 = -X2;
		 _y2 = -Y2;
	 }

	 else if (ang > 225 && ang <= 270)
	 {
		 _x1 = -Y1;
		 _y1 = -X1;
		 _x2 = -Y2;
		 _y2 = -X2;
	 }

	 else if (ang > 270 && ang <= 315)
	 {
		 _x1 = -Y1;
		 _y1 = X1;
		 _x2 = -Y2;
		 _y2 = X2;
	 }

	 else if (ang > 315 && ang <= 360.0)
	 {
		 _x1 = X1;
		 _y1 = -Y1;
		 _x2 = X2;
		 _y2 = -Y2;
	 }

	 else
	 {
		 _x1 = X1;
		 _y1 = Y1;
		 _x2 = X2;
		 _y2 = Y2;
	 }

	 int x = _x1;
	 int y = _y1;
	 int a = _y2 - _y1;
	 int b = _x2 - _x1;
	 int d = 2 * a - b;
	 int E = 2 * a;
	 int NE = 2 * (a - b);



	 while (x < _x2)
	 {
		 if (ang >= 45 && ang < 90)
			 putDaPixel(y, x);

		 else if (ang >= 90 && ang < 135)
			 putDaPixel(-y, x);

		 else if (ang >= 135 && ang < 180)
			 putDaPixel(-x, y);

		 else if (ang >= 180 && ang <= 225)
			 putDaPixel(-x, -y);

		 else if (ang > 225 && ang <= 270)
			 putDaPixel(-y, -x);

		 else if (ang > 270 && ang <= 315)
			 putDaPixel(y, -x);

		 else if (ang > 315 && ang <= 360.0)
			 putDaPixel(x, -y);

		 else
			 putDaPixel(x, y);

		 if (d > 0)
		 {
			 ++y;
			 d += NE;
		 }

		 else
		 {
			 d += E;
		 }

		 ++x;
	 }

	 //
	 //int a = yfinal - yinit;
	 //int b = xfinal - xinit;
	 //int d = 2 * a - b;
	 //int incE = 2 * a, incNE = 2 * (a - b);
	 //int x = xinit, y = yinit;

	 // while (x <= xfinal)
	 // {
		//	 putDaPixel(x, y);
		//	/* putDaPixel(x, HEIGHT - y);
		//	 putDaPixel(-x, y);
		//	 putDaPixel(-x, HEIGHT - y); */
		//	 
		//	 if (d > 0) //punto NE
		//	 {
		//		 ++y;
		//		 d = d + incNE;
		//	 }
		//	 else
		//	 {
		//		 d = d + incE;// punto E
		//	 }
		//	 ++x;
	 // }

	 // x = xinit, y = yinit;
	 // d = 2 * a + b;

	 // while (y <= xfinal)
	 // {
		//  /*putDaPixel(x, y);*/
		///*  putDaPixel(-x, y);
		//  putDaPixel(-x, HEIGHT - y);
		//  putDaPixel(x, HEIGHT - y);*/

		//  if (d > 0) //punto NE
		//  {
		//	  ++x;
		//	  d = d - incNE;
		//  }
		//  else
		//  {
		//	  d = d - incE;// punto E+










		//	  
		//  }
		//  ++y;
	 // }


	 //int a = yfinal - yinit;
	 //int b = xfinal - xinit;
	 //int d = 2 * a - b;
	 //
	 //int x = xinit, y = yinit;

	 // while (x <= xfinal)
	 // {
		//	 putDaPixel(x, y);
		//	 
		//	 if (d > 0) //punto NE
		//	 {
		//		 ++y;
		//		 d = d - 2 * b;
		//	 }
		//	 else
		//	 {
		//		 d = d + 2 * a;// punto E
		//	 }
		//	 ++x;
	 // }

	 //if (x <= xfinal)
	 //{
		// while (x <= xfinal)
		// {

		//	 putDaPixel(x, y);
		//	 if (d > 0) //punto NE
		//	 {
		//		 ++y;
		//		 d = d + incNE;
		//	 }
		//	 else
		//	 {
		//		 d = d + incE;
		//		 --y;
		//	 }
		//	 ++x;
		// }
	 //}
	 //else if (x >= xfinal)
	 //{
		// while (x >= xfinal)
		// {
		//	 
		//	 putDaPixel(x, y);
		//	 if (d > 0) //puto E
		//	 {
		//		 ++y;
		//		 d = d + incNE;
		//	 }
		//	 else
		//	 {
		//		 d = d + incE;
		//		 --y;
		//	 }
		//	 --x;
		// }

		// 
	 //}
 }

 void ej::setColor(Color color)
 {
	 Color newColor(100, 100, 100, 100);

	 color = newColor;
 

 }

 void ej::moveTo(int x, int y)
 {
 
	 currentPositionX = x;
	 currentPositionY = y;
 
 }

 void ej::lineTo(int x, int y)
 {

	
	 line(currentPositionX, currentPositionY, x, y);
	 moveTo(x, y);


 }

 void ej::putDaPixel(const int & x,const int & y)
 {
	 Color c(255, 0, 0, 255);
	 putPixel(x + centerX, -y + centerY , c);

 }

///////////////////////////////////////////////////7
 void ej:: shapeMaker(int lados, int radio)
 {
	 int x;
	 int y;
	 int inc = 360 / lados;
	 moveTo(radio, 0);
	 for (int ang = inc ; ang < 360 ; ang += inc)
	 {
		 x = radio * cos(ang * 3.1416 / 180);
			 y = radio * sin(ang * 3.1416 / 180.0);

			 lineTo(x, y);
	 }
	 lineTo(radio, 0);
 }
 //////////////////////////////////////////////////


void ej::draw()
{

	Color c(255, 0, 0, 255);
	

	//////////////////////////////////////////////
	//TRIANGLES AND SHAPES

	/*shapeMaker(3, 60);
	shapeMaker(3, 70);
	shapeMaker(3, 80);
	shapeMaker(4, 150);
	shapeMaker(5, 250);
	shapeMaker(6, 350);*/

	//////////////////////////////////////////////


	/*for (int x = 0; x < WIDTH/2; ++x)
	{
		putDaPixel(x, HEIGHT / 2);
	}


	for (int a = WIDTH/2; a < HEIGHT; ++a )
	{

		putDaPixel(HEIGHT/2, a);

	}011111111111111111111111111111111111111111111111111111111111111111111111111111111111 

	for (int x = WIDTH / 2; x < HEIGHT; ++x)
	{

		putDaPixel(x, HEIGHT/2);

	}*/
	//////////////////////////////////////

	 
	 

	//////////////////
	
	
	/*clearScreen();*/
	
	
	/*int xAlt;
	int yAlt;
	for (int deg = 90; deg < 440; ++deg)
	{

		xAlt = r * cos(deg * (3.1416 / 180)) + WIDTH / 2;
		yAlt = r * sin(deg * (3.1416 / 180)) + HEIGHT / 2;


		line(WIDTH / 2, HEIGHT / 2, xAlt, yAlt);

		putDaPixel(x, y);
	}*/

	
	
	



	/*line();*/

	int r = 300; 
	for (int deg = 0; deg < 360; deg++)
	{

		int x = r * cos(deg * 3.1416 / 180);
		int y = r * sin(deg * 3.1416 / 180);
		moveTo(0, 0);
		putPixel(x, y, c);

	}

	////////////////////////////////////////////////
	//midpoint con octantes.

	int radio = 300;
	for (int deg = 0; deg < 360; deg++)
	{
		int x = radio * cos(deg * 3.1416 / 180);
		int y = radio * sin(deg * 3.1416 / 180);
		moveTo(0, 0);
		line(0, 0, x, y);
	}

	/////////////////////////////////////////////////


	
}