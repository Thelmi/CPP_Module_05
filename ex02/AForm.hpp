#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string name;
		bool	isSigned;
		const	int	gradeToSign;
		const	int	gradeToExecute;

	public:
		virtual void execute(Bureaucrat const & executor) const = 0;

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

		AForm();
		AForm(const std::string &Name, int SignGrade, int ExecuteGrade);
		AForm(const AForm& other);
		~AForm();
		AForm& operator=(const AForm& other);

		const std::string getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);

} ;
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
