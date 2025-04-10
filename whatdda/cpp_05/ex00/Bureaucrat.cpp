#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
: name("Default"), grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade) : name(Name) 
{
	if (Grade < 1)
		throw GradeTooHighException();
	if (Grade > 150)
		throw GradeTooLowException();
	grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
: name(other.name), grade(other.grade) 
{
	std:: cout << "copy constructor is called " << name << std:: endl;
}

Bureaucrat::~Bureaucrat() 
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) 
		grade = other.grade;
	return *this;
}

const std::string Bureaucrat::getName() const 
{
	return name;
}

int Bureaucrat::getGrade() const 
{
	return grade;
}

void Bureaucrat::increment() 
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement() 
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
	os <<  b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
