#include "Square.h"

Square::Square(int xSp, int ySp, int xInit, int yInit, int width, int height, COLORREF col) : Sprite(xInit, yInit, width, height), xSpeed(xSp), ySpeed(ySp), color(col)
{
	prevX = 0;
	prevY = 0;
	prevSpX = xSp;
	prevSpY = ySp;
}

void Square::Draw(HDC dc)
{
	//Movement with higher speeds doesn't work that well for erasing
	//There are several erasing errors with this code

	Sprite::Draw();

	if (prevSpX == 0 && prevSpY > 0)
	{
		for (int i = 0; i <= height; i++)
		{
			for (int t = 0; t < abs(prevSpY); t++)
			{

				SetPixel(dc, prevX + i, prevY + t, (0, 0, 0));
			}
		}
	}
	else if (prevSpX == 0 && prevSpY < 0)
	{
		for (int i = 0; i <= height; i++)
		{
			for (int t = 0; t < abs(prevSpY); t++)
			{

				SetPixel(dc, prevX + i, prevY + height - t, (0, 0, 0));
			}
		}
	}
	else if (prevSpY == 0 && prevSpX > 0)
	{
		for (int i = 0; i <= width; i++)
		{
			for (int t = 0; t < abs(prevSpX); t++)
			{

				SetPixel(dc, prevX + t, prevY + i, (0, 0, 0));
			}
		}
	}
	else if (prevSpY == 0 && prevSpX < 0)
	{
		for (int i = 0; i <= width; i++)
		{
			for (int t = 0; t < abs(prevSpX); t++)
			{

				SetPixel(dc, prevX + width - t, prevY + i, (0, 0, 0));
			}
		}
	}
	else if (prevSpX > 0 && prevSpY > 0)
	{
		for (int i = 0; i <= height; i++)
		{
			for (int t = 0; t < abs(prevSpY); t++)
			{

				SetPixel(dc, prevX + (i), prevY + t, (0, 0, 0));
			}
		}

		for (int i = 0; i <= width; i++) 
		{
			for (int t = 0; t < abs(prevSpX); t++)
			{
				SetPixel(dc, prevX + t, prevY + (i), (0, 0, 0));
			}
		}
	}
	else if (prevSpY < 0 && prevSpX > 0)
	{
		for (int t = 0; t < abs(prevSpY); t++)
		{
			for (int i = 0; i <= height; i++)
			{
				SetPixel(dc, prevX + t, prevY + height - (i), (0, 0, 0));
			}
		}
		for (int t = 0; t < abs(prevSpX); t++)
		{
			for (int i = 0; i <= width; i++)
			{
				SetPixel(dc, prevX + i, prevY + height - t, (0, 0, 0));
			}
		}
	}
	else if (prevSpY > 0 && prevSpX < 0)
	{
		for (int t = 0; t < abs(prevSpY); t++)
		{
			for (int i = 0; i <= height; i++)
			{
				SetPixel(dc, prevX + width + t, prevY + i, (0, 0, 0));
			}
		}
		for (int t = 0; t < abs(prevSpX); t++)
		{
			for (int i = 0; i <= width; i++)
			{
				SetPixel(dc, prevX + i, prevY + height + t, (0, 0, 0));
			}
		}
	}
	else
	{
		for (int t = 0; t < abs(prevSpY); t++)
		{
			for (int i = 0; i <= height; i++)
			{
				SetPixel(dc, prevX + width - t, prevY + i, (0, 0, 0));
			}
		}
		for (int t = 0; t < abs(prevSpX); t++)
		{
			for (int i = 0; i <= width; i++)
			{
				SetPixel(dc, prevX + i, prevY + height + t, (0, 0, 0));
			}
		}
	}

	int row, column;
	row = 0;
	column = 0;
	for (unsigned i = 0; i < height; i++)
	{
		row = i;
		for (unsigned j = 0; j < width; j++)
		{
			column = j;
			SetPixel(dc, x + column, y + row, color);
		}
	}

}

void Square::Update(int ScreenWidth, int ScreenHeight)
{
	Sprite::Update();


	if (width + x >= ScreenWidth)
	{
		xSpeed *= -1;
	}
	if (height + y >= ScreenHeight)
	{
		ySpeed *= -1;
	}
	if (x < 0)
	{
		xSpeed *= -1;
	}
	if (y < 0)
	{
		ySpeed *= -1;
	}

	prevX = x;
	prevY = y;
	prevSpX = xSpeed;
	prevSpY = ySpeed;
	x += xSpeed;
	y += ySpeed;
}

void Square::ChangeColor(int r, int g, int b)
{
	color = (r, g, b);
}

void Square::Intersects(Square* sq)
{
	if (sq->x > x&& sq->y > y&& sq->x < x + width && sq->y < y + height)
	{
		int tmpX = xSpeed;
		int tmpY = ySpeed;
		xSpeed = sq->xSpeed;
		ySpeed = sq->ySpeed;
		sq->xSpeed = tmpX;
		sq->ySpeed = tmpY;
	}
	else if (sq->width + sq->x > x&& sq->height + sq->y > y&& sq->x + sq->width < x + width && sq->y + sq->height < y + height)
	{
		int tmpX = xSpeed;
		int tmpY = ySpeed;
		xSpeed = sq->xSpeed;
		ySpeed = sq->ySpeed;
		sq->xSpeed = tmpX;
		sq->ySpeed = tmpY;
	}
}