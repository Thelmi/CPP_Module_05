#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default_target") 
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{	
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::action() const
{
	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}

	file << "      /\\      \n";
	file << "     /\\*\\     \n";
	file << "    /\\O\\*\\    \n";
	file << "   /*/\\/\\/\\   \n";
	file << "  /\\O\\/\\*\\/\\  \n";
	file << " /\\*\\/\\*\\/\\/\\ \n";
	file << "/\\O\\/\\/*/\\/O/\\\n";
	file << "      ||      \n";
	file << "      ||      \n";
	file << "      ||      \n";

	file.close();
	std::cout << "Shrubbery created in " << filename << std::endl;
}