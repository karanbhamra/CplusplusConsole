#include <iostream>
#include <string>
#include <Windows.h>
#include "Square.h"

int main()
{
	//key up 72
	//key down 80
	//key right 77
	//key left 75
	//_getch() to get the char of the key pressed (would need to create another thread)

	using std::fmod;

	HWND myconsole = GetConsoleWindow();
	COLORREF Color = (255, 255, 255);

	HDC dc = GetDC(myconsole);

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;


	Square square(1, 1, 0, 0, 50, 50, (255, 255, 255));//Collor is always red for some reason

	Square square2(1, 1, 500, 300, 30, 30, (100, 70, 180));

	Square square3(1, 1, 325, 100, 25, 25, (255, 200, 100));

	Square square4(5, 5, 200, 40, 8, 8, (225, 70, 180));

	while (true)
	{
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		square.Draw(dc);
		square2.Draw(dc);
		square3.Draw(dc);
		square4.Draw(dc);
		

		square.Update(columns * 8, rows * 16);//16 pixels per row, 8 pixels per column

		square2.Update(columns * 8, rows * 16);

		square3.Update(columns * 8, rows * 16);

		square4.Update(columns * 8, rows * 16);

		square.Intersects(&square2);
		square.Intersects(&square3);
		square.Intersects(&square4);

		square2.Intersects(&square3);
		square2.Intersects(&square4);

		square3.Intersects(&square4);
	}

	ReleaseDC(myconsole, dc);

}