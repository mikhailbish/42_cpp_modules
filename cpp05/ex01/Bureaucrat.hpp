#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		unsigned char _grade;
		void _checkGrade(unsigned char _grade);
	public:
		Bureaucrat();
		explicit Bureaucrat(std::string, unsigned char);
		Bureaucrat(Bureaucrat& other);
//TODO: think through and copy to the other exercises
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		unsigned char getGrade() const;
		void promote();
		void demote();
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
		void signForm(Form &);
};
std::ostream &operator<<(std::ostream &, const Bureaucrat &);
#endif
