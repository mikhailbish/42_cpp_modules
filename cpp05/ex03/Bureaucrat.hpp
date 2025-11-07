#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		unsigned char _grade;
		void _checkGrade(unsigned char _grade);
	public:
		Bureaucrat();
		explicit Bureaucrat(std::string, unsigned char);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &other) = delete;
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
		void signForm(AForm &);
		void executeForm(AForm const & form);
};
std::ostream &operator<<(std::ostream &, const Bureaucrat &);
#endif
