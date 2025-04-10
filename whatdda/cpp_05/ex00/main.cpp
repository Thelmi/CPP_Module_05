#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "Creating a bureaucrat with grade 1 (valid)..." << std::endl;
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;

		std::cout << "Incrementing Alice (should throw exception)..." << std::endl;
		b1.increment();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nCreating a bureaucrat with grade 150 (valid)..." << std::endl;
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;

		std::cout << "Decrementing Bob (should throw exception)..." << std::endl;
		b2.decrement();
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "\nCreating a bureaucrat with grade 0 (invalid)..." << std::endl;
		Bureaucrat b3("Charlie", 0);
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "\nCreating a bureaucrat with grade 151 (invalid)..." << std::endl;
		Bureaucrat b4("David", 151);
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "\nTesting copy constructor and assignment operator..." << std::endl;
		Bureaucrat b5("Emma", 50);
		Bureaucrat b6 = b5;
		Bureaucrat b7("Frank", 100);
		b7 = b5;

		std::cout << "Original: " << b5 << std::endl;
		std::cout << "Copy: " << b6 << std::endl;
		std::cout << "Assigned: " << b7 << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
