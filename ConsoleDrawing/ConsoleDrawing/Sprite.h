#pragma once
class Sprite
{
protected:
	int x;
	int y;
	int width;
	int height;

public:
	Sprite(int xInit, int yInit, int width, int height);

	virtual void Draw();

	virtual void Update();
private:

};