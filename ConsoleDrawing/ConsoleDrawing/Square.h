#pragma once
#include "Sprite.h"
#include "Color.h"
class Square : protected Sprite
{
public:
	Square(int xSp, int ySp, int xInit, int yInit, int width, int height, Util::Color drawColor, Util::Color eraseColor);

	void Draw(HDC dc, Util::Rectangle hitbox, Util::Color col);

	void Update(int ScreenHeight, int ScreenWidth) override;

	void ChangeColor(unsigned char r, unsigned char g, unsigned char b);

	void UpdatePreviousHitbox(Util::Rectangle hitbox);

	Util::Rectangle GetCurrentHitbox() const;
	Util::Rectangle GetPreviousHitbox() const;

	Util::Color GetDrawColor() const;
	Util::Color GetEraseColor() const;
	int GetXSpeed() const;
	int GetYSpeed() const;

	void SetYSpeed(int yspeed);
	void SetXSpeed(int xspeed);

	void Intersects(Square& sq);
private:
	int xSpeed{};
	int ySpeed{};
	Util::Color drawColor{};
	Util::Color eraseColor{};

};
