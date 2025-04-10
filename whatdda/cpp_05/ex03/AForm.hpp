#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const	std::string name;
		bool	isSigned;
		const	int	gradeToSign;
		const	int	gradeToExecute;
	protected:
		virtual void action() const = 0;
	public:
		AForm();
		AForm(const std::string &Name, int SignGrade, int ExecuteGrade);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

		const std::string getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
} ;
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
