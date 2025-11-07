#ifndef PRESIDENTIAL_PARDON_FORM_HPP 
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm {
	private:
		virtual void _execute() const override;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other) = delete;
		~PresidentialPardonForm();
		
};

#endif
