#pragma once
#include <Windows.h>

#include "Rectangle.h"
class Sprite
{
protected:
	int x{};
	int y{};
	int width{};
	int height{};

	Util::Rectangle currentHitbox;
	Util::Rectangle previousHitbox;


public:
	Sprite() {};
	virtual void Update(int ScreenHeight, int ScreenWidth) = 0;
private:

};