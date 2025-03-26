#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* invalidForm;

    form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
    invalidForm = someRandomIntern.makeForm("unknown form", "Test");

    if (form1) 
    {
        Bureaucrat b1("Martin", 1);
        b1.signForm(*form1);
        b1.executeForm(*form1);
        delete form1;
    }

    if (form2)
    {
        Bureaucrat b2("Sarah", 45);
        b2.signForm(*form2);
        b2.executeForm(*form2);
        delete form2;
    }

    if (form3) 
    {
        Bureaucrat b3("President", 5);
        b3.signForm(*form3);
        b3.executeForm(*form3);
        delete form3;
    }
    return 0;
}
