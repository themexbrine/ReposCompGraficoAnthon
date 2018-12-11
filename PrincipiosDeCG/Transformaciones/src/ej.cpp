#include "ej.h"
#include <math.h>
#include "Vec3.h"
#include "Matrix3.h"
#define _USE_MATH_DEFINES

#include <cmath>

ej::ej() : BaseApplication()
{
	//ya estaban inicializadas 
	//No pertenecian a Base Application
	centerX = WIDTH / 2;
	centerY = HEIGHT / 2;
	currentPositionX = 0;
	currentPositionY = 0;
	 
}
		
ej::~ej()
{

	 
}

 void ej::setup()
{
	 
	 Vec3 test(0, 0);
	 Vec3 a(0, 0);
	 Vec3 b(100, 100);
	 Vec3 d(200, 0);
	 serpinsky(2, a, b, d);
	 //Aqui debes ejecutar el  Sierpinsky y nunca mas en otro lado
	 
}

 void ej::update()
 {
	 //degrees -= 0.05f;
	 //portal infinito 
	 degrees -= 5.0f;
	 //
	 //borramos el contenido del verticesTransformados
	 //verticesTransformados.clear();
	 verticesTransformados.clear();

	 
	
	 

	//Aqui tienes que crear tus matrices de transformacion 
	//Por ejemplo:
	 // ++ang;  //incrementamos el angulo de rotacion
	 //Matrix3 rotation = Matrix3::Rotate(ang); 
	 //Matrix3 scale = Matrix3::Scale(Vec3(2, 2));  //ejemplo de escala al doble de tamaño
	 //Matrix3 accum = rotation * scale;

	 //luego transofmras uno por uno todos los vertices y vas guardanto cada uno en otro vector (verticesTransformados)
	//Matrix3 rotation = Matrix3::rotate(degrees);   //aqui creas una matriz de rotacion
	 for (int i = 0; i < vertices.size(); i++)
	 {
		 // = rotation * vertices[i];  //multiplicas la matriz por cada uno de los vectores (usando la sobrecarga del operador "*")
		
		Matrix3 rot = Matrix3::rotate(degrees);
		Vec3 aaa(50, 50);
		Matrix3 sca = Matrix3::scale(3 , 3);
		Matrix3 tran = Matrix3::translate(aaa);
		Matrix3 Total = rot * sca * tran;
		Vec3 result = Total * vertices[i];
		//esto esta mal. Tiemes que crear una matriz de rotacion
		 verticesTransformados.push_back(result); // cheque matrix3.h
	 }

	 /*for (auto v : vertices)
		verticesTransformados.push_back(accum * v);*/ //guardamos uno a uno todos los vertices transformados
	 
	 
 }

 void ej::clearScreen()
 {
	 Color eraser(0, 0, 0, 0); ///esto tiene que ser el color de "setColor"
	 setColor(eraser);

	 for (int i = -WIDTH; i < WIDTH; i++)
	 {
		 
		 for (int y = -HEIGHT; y < HEIGHT; y++)
		 {
			 putPixel(i, y, eraser);
		 }
	 }
		 
	 

 }

 void ej::line(int X1, int Y1, int X2, int Y2)
 {

	 float ang = 0.0;
	 int _x1 = 0;
	 int _y1 = 0;
	 int _x2 = 0;
	 int _y2 = 0;

	 ang = (atan2(Y2 - Y1, X2 - X1) * (180.0 / 3.1416));

	 /*if (ang >= 0.0)
	 {
		 if (Y2 < 0)
			 ang = 359;
		 else
			 ang = ang;
	 }*/

	 if (ang < 0.0)
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

 void ej::triangle(Vec3 a, Vec3 b, Vec3 c)
 {
	//El color no se define aqui, se define en la funcion draw (con el setcolor)
	 moveTo(a.x, a.y);
	 lineTo(b.x, b.y);

	 lineTo(c.x, c.y);//no se esta pintando

	 lineTo(a.x, a.y);
 }



 void ej::setColor(Color color)
 {
	 //Color newColor(100, 100, 100, 100);  //??????

	 //color = newColor; //  ???????????
	 currentColor = color;
 

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

 void ej::LineVec(Vec3 a, Vec3 b)
 {
	 line(a.x, a.y, b.x, b.y);
 }

 void ej::lineToVec(Vec3 b)
 {


	 line(currentPositionX, currentPositionY, b.x, b.y);
	 moveTo(b.x, b.y);


 }

 void ej::putDaPixel(const int & x,const int & y)
 {
	 ///Color c(255, 0, 0, 255);  MAL!!!!!! tiene que ser el current color !!!!
	 putPixel(x + centerX, -y + centerY , currentColor);

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

  Vec3 ej::MidVec(Vec3 a, Vec3 b)
  {
	   Vec3 mid((a.x + b.x)/2.0 , (a.y + b.y)/2.0);
	   return mid;
  }
 //////////////////////////////////////////////////

 void ej::serpinsky(int subdiv, Vec3 a, Vec3 b, Vec3 c)
 {
	 if (subdiv <= 0)
	 {
		 //En vez de dibujar el traiangulo aqui, debes insertar los vertices a,b,c en un vector "vertices"
		 vertices.push_back(a);
		 vertices.push_back(b);
		 vertices.push_back(c);
		 
	 }
	 else
	 {
		 Vec3 ab = MidVec(a, b);
		 Vec3 bc = MidVec(b, c);
		 Vec3 ca = MidVec(c, a);

		 serpinsky(subdiv - 1, a, ab, ca);
		 serpinsky(subdiv - 1, ab, b, bc);
		 serpinsky(subdiv - 1, ca, bc, c);


	 }
	 
 }

 Vec3 ej::RotateZ(int grados, Vec3 Vector)
 {
	 Vec3 e;
	

	 float mat [3][3] = 
	 {
		{cos(grados),(-sin(grados)), 0},
		{sin(grados),cos(grados), 0},
		{0 , 0, 1}
	 };

	 e.x = ((Vector.x)*mat[0][0]) + (Vector.y*mat[1][0]);
	 e.y = (mat[0][1]*(Vector.x)) + mat[1][1]* Vector.y;

	
	 return e;
	 
	
 }

void ej::draw()
{	//ojo: das el color para borrar pantalla aqui !!! (usa setColor)

	clearScreen();
	setColor(Color(0, 255, 0, 255));
	//OJO: das el color para pintar (usa setColor de nuevo)
	for (int i = 0; i < verticesTransformados.size(); i += 3) //vamos de 3 en 3 porque son 3 puntos por triangulo
	{
		triangle(verticesTransformados[i],verticesTransformados[i + 1],verticesTransformados[i + 2]);
	}

	

	/*
		setColor(black); // Anthon: da los valores para un color negro
		Borramos pantalla con un clearScreen();
		setColor(red); //Anthon pon un color rojo o el que quieras

		//Dibujamos el sierpinsky ya transfomado. Los datos estan en "verticesTransformados"
		for (int i = 0; i < verticesTransformados.size(); i += 3) //vamos de 3 en 3 porque son 3 puntos por triangulo
			triangle(verticesTransformados[i],
					verticesTransformados[i+1],
					verticesTransformados[i+2]);

		//Esto es todo el draw.

	*/


	/*Color c(255, 0, 0, 255);
	Vec3 a(0, 0);
	Vec3 b(100, 100);
	Vec3 d(200, 0);*/

	
	

	//,(b.y)*(-sin(90)))
	//int grados = 180;
	//Vec3 bPrim( ((b.x)*cos(grados)) + (b.y*(-sin(grados))),
	//	(sin(grados)*(b.x)) + (cos(grados)*b.y)  );

	//Vec3 dPrim(((d.x)*cos(grados)) + (d.y*(-sin(grados))),
	//	(sin(grados)*(d.x)) + (cos(grados)*d.y));

	//serpinsky(2, a, RotateZ(0, b), RotateZ(0, d));
	///*serpinsky(2, a, RotateZ(180, b), RotateZ(180, d) );*/

	//serpinsky(2, a, bPrim, dPrim);

	//triangle(a, b, d);
	//
	//serpinsky(2, a, bPrim, dPrim);
	




	
	

	
	
}
//void ej::RotateZ(int grados, Vec3 Vector, Vec3 Vector2, Vec3 Vector3)
//{
//	Vec3 e;
//	Vec3 f;
//
//	float mat[3][3] =
//	{
//	   {cos(grados),(-sin(grados)), 0},
//	   {sin(grados),cos(grados), 0},
//	   {0 , 0, 1}
//	};
//
//	e.x = ((Vector2.x)*mat[0][0]) + (Vector2.y*mat[1][0]);
//	e.y = (mat[0][1] * (Vector2.x)) + mat[1][1] * Vector2.y;
//
//	f.x = ((Vector3.x)*mat[0][0]) + (Vector3.y*mat[1][0]);
//	f.y = (mat[0][1] * (Vector3.x)) + mat[1][1] * Vector3.y;
//
//
//	serpinsky(2, Vector, e, f);
//
//}