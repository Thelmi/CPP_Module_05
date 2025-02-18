#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat 
{
	private:
		const std::string name;
		int grade;

	public:
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

		Bureaucrat();
		Bureaucrat(const std::string &Name, int Grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string getName() const;
		int getGrade() const;

		void increment();
		void decrement();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
