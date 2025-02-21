#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 5);

        Form taxForm("Tax Form", 10, 50);
        Form jobApplication("Job Application", 150, 50);

        std::cout << taxForm << std::endl;
        std::cout << jobApplication << std::endl;

        bob.signForm(taxForm);
        alice.signForm(taxForm);

        bob.signForm(jobApplication);
        alice.signForm(jobApplication);

        std::cout << taxForm << std::endl;
        std::cout << jobApplication << std::endl;

    } catch (const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
