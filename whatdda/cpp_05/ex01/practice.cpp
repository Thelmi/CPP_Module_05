#include <iostream>

class Shape
{
	public:
		virtual void draw() = 0;
};

class Circle : public Shape
{
	public:
		void draw()
		{
			std:: cout << "Drawing a Circle!" << std::endl;
		}
};

class Rectangle : public Shape
{
	public:
		void draw()
		{
			std:: cout << "Drawing a Rectangle!" << std::endl;
		}
};

int main()
{
	Shape *shape;
	Circle circle;
	Rectangle rectangle;

	shape = &circle;

	shape->draw();

	shape = &rectangle;

	shape->draw();

}
