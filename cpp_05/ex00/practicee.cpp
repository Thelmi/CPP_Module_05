#include <iostream>
#include <exception>

class Dad
{
	public:
		virtual void houseMen() const
		{
			std:: cout << "Bluh Bluh Bluh" << std:: endl;
		}
		class Errors : public std:: exception
		{
			virtual const char *what() const throw()
			{
				return "Too young";
			}
		};
};

class Brother : public Dad
{
	private:
		int age;
	public:
		Brother()
		{
			age = 1;
		}
		void houseMen() const
		{
			if (age < 18)
			{
				throw Errors();
			}
			std:: cout << "NAH NAH NAH" << std:: endl;
		}
} ;

int main ()
{
	Dad *father;
	
	Brother bruh;
	
	father = &bruh;
	try
	{
		father->houseMen();
	}
	catch(const std::exception &e)
	{
		std:: cout << e.what() << std::endl;
	}
}