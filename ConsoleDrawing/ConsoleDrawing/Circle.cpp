#include "Circle.h"

Circle::Circle(int xSp, int ySp, int xInit, int yInit, int width, int height, Util::Color drawColor, Util::Color eraseColor)
{
	this->xSpeed = xSp;
	this->ySpeed = ySp;
	this->x = xInit;
	this->y = yInit;
	this->width = width;
	this->height = height;
	this->drawColor = drawColor;
	this->eraseColor = eraseColor;
}

void Circle::Draw(HDC dc, Util::Color color, bool isFilled)
{
	float angle = 0;
	float anglestep = 0.01f;

	int maxradius = width / 2;

	int centerx = x + maxradius;
	int centery = y + maxradius;

	int count = 0;
	while (angle < 2 * 3.14)
	{
		for (float radius = 0; radius < maxradius; radius+=0.7f)
		{
			int tempx = radius * cos(angle);
			int tempy = radius * sin(angle);
			int valx = tempx + centerx;
			int valy = tempy + centery;

			SetPixel(dc, valx, valy, color.getRGB());
		}
		angle += anglestep;
		count++;
	}

	count;

}

void Circle::Update(int ScreenHeight, int ScreenWidth)
{
}

void Circle::ChangeColor(unsigned char r, unsigned char g, unsigned char b)
{
	drawColor.setRGB(r, g, b);

}

void Circle::UpdatePreviousHitbox(Util::Rectangle hitbox)
{
	previousHitbox = hitbox;

}

Util::Rectangle Circle::GetCurrentHitbox() const
{
	return currentHitbox;
}

Util::Rectangle Circle::GetPreviousHitbox() const
{
	return previousHitbox;
}

Util::Color Circle::GetDrawColor() const
{
	return drawColor;
}

Util::Color Circle::GetEraseColor() const
{
	return eraseColor;
}

int Circle::GetXSpeed() const
{
	return xSpeed;
}

int Circle::GetYSpeed() const
{
	return ySpeed;
}

void Circle::SetYSpeed(int yspeed)
{
	ySpeed = yspeed;
}

void Circle::SetXSpeed(int xspeed)
{
	xSpeed = xspeed;

}

void Circle::Intersects(Circle& sq)
{
}
