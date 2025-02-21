#include "AForm.hpp"
#include "Bureaucrat.hpp"


const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low!";
}

AForm:: AForm() 
	: name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) 
{
	
}

AForm:: AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm:: AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{

}

AForm:: ~AForm() 
{

}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

const std::string AForm::getName() const 
{
	return name;
}

bool AForm::getIsSigned() const 
{
	return isSigned;
}

int AForm::getGradeToSign() const 
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) 
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform) 
{
	os << "Form \"" << Aform.getName() << "\" is "
	   << (Aform.getIsSigned() ? "signed" : "not signed")
	   << ". Grade required to sign: " << Aform.getGradeToSign()
	   << ", grade required to execute: " << Aform.getGradeToExecute();
	return os;
}
