#pragma once
#include "Sprite.h"
#include <Windows.h>

class Square : Sprite
{
public:
	Square(int xSp, int ySp, int xInit, int yInit, int width, int height, COLORREF col);

	void Draw(HDC dc);

	void Update(int ScreenHeight, int ScreenWidth);

	void ChangeColor(int r, int g, int b);

	void Intersects(Square* sq);
private:
	int xSpeed;
	int ySpeed;
	COLORREF color;
	int prevX;
	int prevY;
	int prevSpX;
	int prevSpY;
};
