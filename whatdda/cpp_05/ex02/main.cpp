#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrubForm("cola");
		RobotomyRequestForm roboForm("Bender");
		PresidentialPardonForm pardonForm("Arthur Dent");

		bob.executeForm(shrubForm);

		bob.signForm(shrubForm);
		bob.signForm(roboForm);
		bob.signForm(pardonForm);

		bob.executeForm(shrubForm);
		bob.executeForm(roboForm);
		bob.executeForm(roboForm);
		bob.executeForm(roboForm);
		bob.executeForm(roboForm);
		bob.executeForm(pardonForm);
	}
	catch (std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}


