#ifndef ROBOTOMY_REQUEST_FORM_HPP 
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <iostream>


class RobotomyRequestForm : public AForm {
	private:
		virtual void _execute() const override;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = delete;
		~RobotomyRequestForm();
		
};

#endif
