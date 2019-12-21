#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <ctime>
#include "Square.h"
#include "Circle.h"

int main()
{
	//key up 72
	//key down 80
	//key right 77
	//key left 75
	//_getch() to get the char of the key pressed (would need to create another thread)

	srand(time(nullptr));

	HWND myconsole = GetConsoleWindow();
	COLORREF Color = (255, 255, 255);

	HDC dc = GetDC(myconsole);

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;


	//Square square(10, 10, 0, 0, 50, 50, Util::Color(0, 255, 0), Util::Color(12, 12, 12));
	//Square square2(-10, 10, 500, 0, 50, 50, Util::Color(255, 255, 0), Util::Color(12, 12, 12));

	Circle circle(10, 10, 50, 50, 150, 150, Util::Color(0, 255, 0), Util::Color(12, 12, 12));

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	while (true)
	{ 
		//circle.ChangeColor(rand() % 256, rand() % 256, rand() % 256);
		circle.Draw(dc, circle.GetDrawColor());
		
		/*square.Intersects(square2);
		square.Draw(dc, square.GetPreviousHitbox(), square.GetEraseColor());
		square2.Draw(dc, square2.GetPreviousHitbox(), square2.GetEraseColor());
		square.Update(columns * 8, rows * 16);
		square2.Update(columns * 8, rows * 16);
		square.Draw(dc, square.GetCurrentHitbox(), square.GetDrawColor());
		square2.Draw(dc, square2.GetCurrentHitbox(), square2.GetDrawColor());
		square.UpdatePreviousHitbox(square.GetCurrentHitbox());
		square2.UpdatePreviousHitbox(square2.GetCurrentHitbox());*/

	}

	ReleaseDC(myconsole, dc);

}