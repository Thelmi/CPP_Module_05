#include <iostream>
#include <exception>

class ArthiErrors
{
	private:
		int a;
		int b;

	public:
		ArthiErrors();
		ArthiErrors(int A, int B);
		~ArthiErrors();
		int getA();
		int getB();
		int division();
	class Division_by_zero : public std:: exception
	{
		public:
			const char *what() const throw();
	};
	Division_by_zero zero;
}; 

const char *ArthiErrors:: Division_by_zero:: what() const throw()
{
	return "Dividing by zero is not preferable";
} 
ArthiErrors::ArthiErrors()
{
    std::cout << "Object has been constructed" << std::endl;
    a = 0;
    b = 0;
}

ArthiErrors::ArthiErrors(int A, int B)
{
	std::cout << "Object has been constructed" << std::endl;
    a = A;
    b = B;
}

ArthiErrors::~ArthiErrors()
{
    std::cout << "Object has been destroyed" << std::endl;
}

int ArthiErrors::getA()
{
    return a;
}

int ArthiErrors::getB()
{
	return b;
}

int ArthiErrors::division()
{
	if (a == 0 || b == 0)
		throw Division_by_zero();
	return (a / b);
}

int addone(int result)
{
	return result + 1;
}

int main()
{
	try
	{
		int result;
		ArthiErrors operations(0, 10);
		result = operations.division();
		result = addone(result);
		std::cout << operations.getA() << std::endl;
		std::cout << operations.getB() << std::endl;
		std::cout << result << std::endl;
	}
	catch(const ArthiErrors:: Division_by_zero &e)
	{
		std:: cout << e.what() << std:: endl;
	}
}
