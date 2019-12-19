#pragma once
#include <Windows.h>
namespace Util
{
	class Color
	{
	private:
		unsigned char red{};
		unsigned char green{};
		unsigned char blue{};

	public:
		Color() = default;
		Color(int r, int g, int b);
		unsigned char getRed() const;
		unsigned char getGreen() const;
		unsigned char getBlue() const;

		void setRed(unsigned char val);
		void setGreen(unsigned char val);
		void setBlue(unsigned char val);

		COLORREF getRGB() const;
		void setRGB(unsigned char r, unsigned char g, unsigned char b);
	};
}

