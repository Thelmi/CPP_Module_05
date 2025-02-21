#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
public:
    ShrubberyCreationForm(const std::string& target);
	
    virtual ~ShrubberyCreationForm();
    virtual void execute(Bureaucrat const & executor) const;
};

#endif
