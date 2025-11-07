#ifndef FORM_HPP 
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const unsigned char _gradeSign;
		const unsigned char _gradeExec;
		void _checkGrade(unsigned char _grade);
	public:
		Form();
		explicit Form(std::string name, unsigned char gradeSign, unsigned char gradeExec);
		~Form();
		Form(Form &);
		Form &operator=(const Form &other);
		std::string getName() const;
		bool getIsSigned() const;
		unsigned char getGradeSign() const;
		unsigned char getGradeExec() const;
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
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
		void beSigned(Bureaucrat &);
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif
