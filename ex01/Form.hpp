#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
	private:
		const	std::string Name;
		bool	isSigned;
		const	int	signGrade;
		const	int	executeGrade;

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
		Form(const std::string &Name);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

		const std::string getName() const;
		bool	getIsSigned() const;
		const	int	getSignGrade() const;
		const	int	getExecuteGrade() const;

		void beSigned(Bureaucrat b);

} ;

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
