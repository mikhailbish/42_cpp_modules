#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		virtual void _execute() const override;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete;
		~ShrubberyCreationForm();
		
};

#endif
