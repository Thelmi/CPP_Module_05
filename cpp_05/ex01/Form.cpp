#include "Form.hpp"
#include "Bureaucrat.hpp"


const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

Form:: Form() 
	: name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) 
{

}

Form:: Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form:: Form(const Form &other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{

}

Form:: ~Form() 
{

}

Form &Form::operator=(const Form &other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

const std::string Form::getName() const 
{
	return name;
}

bool Form::getIsSigned() const 
{
	return isSigned;
}

int Form::getGradeToSign() const 
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) 
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) 
{
	os << "Form \"" << form.getName() << "\" is "
	   << (form.getIsSigned() ? "signed" : "not signed")
	   << ". Grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExecute();
	return os;
}
