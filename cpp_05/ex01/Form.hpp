#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const	std::string name;
		bool	isSigned;
		const	int	gradeToSign;
		const	int	gradeToExecute;

	public:
		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};

		Form();
		Form(const std::string &Name, int SignGrade, int ExecuteGrade);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

		const std::string getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
} ;

std::ostream& operator<<(std::ostream& os, const Form& f);
#endif
