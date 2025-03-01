#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat tom("Tom", 150);

		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Alice");
		
		std::cout << "\n--- Attempting to sign forms with Tom (low grade) ---" << std::endl;
		try
		{
			shrub.beSigned(tom);
			std::cout << shrub << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << tom.getName() << " couldn't sign " << shrub.getName() 
						<< " because " << e.what() << std::endl;
		}

		try
		{
			robot.beSigned(tom);
			std::cout << robot << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << tom.getName() << " couldn't sign " << robot.getName() 
						<< " because " << e.what() << std::endl;
		}
		try
		{
			pardon.beSigned(tom);
			std::cout << pardon << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << tom.getName() << " couldn't sign " << pardon.getName() 
						<< " because " << e.what() << std::endl;
		}
		
		std::cout << "\n--- Bob (high grade) signs the forms ---" << std::endl;
		shrub.beSigned(bob);
		robot.beSigned(bob);
		pardon.beSigned(bob);
		
		std::cout << "\n--- Bob executes the forms ---" << std::endl;
		bob.executeForm(shrub);
		bob.executeForm(robot);
		bob.executeForm(pardon);
		
	} catch (std::exception &e) {
		std::cout << "Exception caught in main: " << e.what() << std::endl;
	}
	return 0;
}