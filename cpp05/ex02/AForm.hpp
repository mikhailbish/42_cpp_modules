#ifndef AFORM_HPP 
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const unsigned char _gradeSign;
		const unsigned char _gradeExec;
		std::string _target;
		void _checkGrade(unsigned char _grade);
		virtual void _execute() const = 0;
	public:
		AForm();
		AForm(std::string name, unsigned char gradeSign, unsigned char gradeExec, std::string);
		virtual ~AForm();
		AForm(AForm &);
		AForm &operator=(const AForm &other) = delete;
		std::string getName() const;
		bool getIsSigned() const;
		std::string getTarget() const;
		void setTarget(std::string target);
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
		class AFormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
		class AFormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
		void beSigned(Bureaucrat &);
		void execute(Bureaucrat const &) const;
};

std::ostream &operator<<(std::ostream &, const AForm &);

#endif
