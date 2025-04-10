
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() 
{
    std::cout << "Intern created!" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copied!" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        std::cout << "Intern assigned!" << std::endl;
    }
    return *this;
}

Intern:: ~Intern()
{
    std::cout << "Intern destroyed!" << std::endl;
}

AForm* createShrubbery(std::string target)
{ 
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target)
{ 
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) 
{
    const std::string formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(std::string) = {createShrubbery, createRobotomy, createPresidential};

    for (int i = 0; i < 3; i++) 
    {
        if (formTypes[i] == formName) 
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Error: Form '" << formName << "' does not exist!" << std::endl;
    return 0;
}
