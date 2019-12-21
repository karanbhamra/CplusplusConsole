#pragma once

namespace Util
{
	class Rectangle
	{
	private:
		int x{};
		int y{};
		int width{};
		int height{};

	public:
		Rectangle() = default;
		Rectangle(int tx, int ty, int tw, int th);

		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		bool IntersectsWith(Util::Rectangle other) const;

	};
}

