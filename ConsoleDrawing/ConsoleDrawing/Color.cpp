#include "Color.h"


Util::Color::Color(int r, int g, int b)
{
	setRGB(r, g, b);
}

unsigned char Util::Color::getRed() const
{
	return red;
}

unsigned char Util::Color::getGreen() const
{
	return green;
}

unsigned char Util::Color::getBlue() const
{
	return blue;
}

void Util::Color::setRed(unsigned char val)
{
	red = val;
}

void Util::Color::setGreen(unsigned char val)
{
	green = val;
}

void Util::Color::setBlue(unsigned char val)
{
	blue = val;
}

COLORREF Util::Color::getRGB() const
{
	return RGB(red, green, blue);
}

void Util::Color::setRGB(unsigned char r, unsigned char g, unsigned char b)
{
	setRed(r);
	setGreen(g);
	setBlue(b);
}
