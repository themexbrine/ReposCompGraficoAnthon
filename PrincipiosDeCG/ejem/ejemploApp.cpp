#include "ejemploApp.h"


void ejemploApp::setup()
{



}

void ejemploApp::update()
{



}

void ejemploApp::draw()
{

	Color c(255, 0, 0, 0);
	c.R(255);
	c.G(0);
	c.B(0);
	c.A(0);

	for (int x = 0; x < 1024; ++x)
	{
		putPixel(x, HEIGHT / 2, c);
	}

	for (int y = 0; y < 1024; ++y)
	{
		putPixel(WIDTH / 2, y, c);
	}

	for (int x = 0; x < 1024; ++x)
	{
		putPixel(x, x, c);
	}

	int a = 0;
	for (int x = 1024; x >0; --x)
	{
		a = a + 1;
		putPixel(x, a, c);
	}
	
}