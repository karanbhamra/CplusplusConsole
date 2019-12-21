#include "Rectangle.h"

Util::Rectangle::Rectangle(int tx, int ty, int tw, int th) : x(tx), y(ty), width(tw), height(th) {}

int Util::Rectangle::getX() const { return x; }
int Util::Rectangle::getY() const { return y; }
int Util::Rectangle::getWidth() const { return width; }
int Util::Rectangle::getHeight() const { return height; }

bool Util::Rectangle::IntersectsWith(Util::Rectangle other) const
{
    if (x < other.x + other.width &&
        x + width > other.x&&
        y < other.y + other.height &&
        y + height > other.y) {
        // collision detected!
        return true;
    }
	return false;
}
