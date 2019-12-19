#include "Square.h"



Square::Square(int xSp, int ySp, int xpos, int ypos, int width, int height, Util::Color drawColor, Util::Color eraseColor)
{
	this->x = xpos;
	this->y = ypos;
	this->xSpeed = xSp;
	this->ySpeed = ySp;
	this->width = width;
	this->height = height;
	this->drawColor = drawColor;
	this->eraseColor = eraseColor;
	currentHitbox = Util::Rectangle::Rectangle(x, y, width, height);
	previousHitbox = currentHitbox;

}



void Square::Draw(HDC dc, Util::Rectangle hitbox, Util::Color color)
{
	// erase previous hitbox
	// we must use the RGB macro which has 3 parameters, each byte represents r,g, b

	/*auto tempColor = Util::Color::Color(12, 12, 12);
	for (size_t row = 0; row < height; row++)
	{
		for (size_t col = 0; col < width; col++)
		{
			SetPixel(dc, static_cast<int>(previousHitbox.getX() + col), static_cast<int>(previousHitbox.getY() + row), tempColor.getRGB());

		}
	}*/

	//system("cls");

	// draw current hitbox
	// we must use the RGB macro which has 3 parameters, each byte represents r,g, b
	for (size_t row = 0; row < height; row++)
	{
		for (size_t col = 0; col < width; col++)
		{
			SetPixel(dc, static_cast<int>(currentHitbox.getX() + col), static_cast<int>(currentHitbox.getY() + row), color.getRGB());

		}
	}

}

void Square::Update(int ScreenWidth, int ScreenHeight)
{
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

	x += xSpeed;
	y += ySpeed;
	currentHitbox = Util::Rectangle::Rectangle(x, y, width, height);

}

void Square::ChangeColor(unsigned char r, unsigned char g, unsigned char b)
{
	drawColor.setRGB(r, g, b);
}

void Square::UpdatePreviousHitbox(Util::Rectangle hitbox)
{
	previousHitbox = hitbox;
}

Util::Rectangle Square::GetCurrentHitbox() const
{
	return currentHitbox;
}

Util::Rectangle Square::GetPreviousHitbox() const
{
	return previousHitbox;
}

Util::Color Square::GetDrawColor() const
{
	return drawColor;
}

Util::Color Square::GetEraseColor() const
{
	return eraseColor;
}

int Square::GetXSpeed() const
{
	return xSpeed;
}

int Square::GetYSpeed() const
{
	return ySpeed;
}

void Square::SetYSpeed(int yspeed)
{
	ySpeed = yspeed;
}

void Square::SetXSpeed(int xspeed)
{
	xSpeed = xspeed;
}

void Square::Intersects(Square& sq)
{
	if (sq.GetCurrentHitbox().IntersectsWith(this->GetCurrentHitbox()))
	{
		auto tempx = this->GetXSpeed();
		auto tempy = this->GetYSpeed();

		SetYSpeed(sq.GetYSpeed());
		SetXSpeed(sq.GetXSpeed());

		sq.SetXSpeed(tempx);
		sq.SetYSpeed(tempy);
	}
	/*if (sq->x > x&& sq->y > y&& sq->x < x + width && sq->y < y + height)
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
	}*/
}