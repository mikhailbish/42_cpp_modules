#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeSign(150), _gradeExec(150)
{}

Form::Form(std::string name, unsigned char gradeSign, unsigned char gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	_checkGrade(gradeSign);
	_checkGrade(gradeExec);
}

Form::Form(Form &other) : _name(other._name), _isSigned(false), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

unsigned char Form::getGradeSign() const
{
	return _gradeSign;
}

unsigned char Form::getGradeExec() const
{
	return _gradeExec;
}

void Form::beSigned(Bureaucrat &signee)
{
	if (signee.getGrade() > _gradeSign)
		throw GradeTooLowException();
	if (_isSigned)
		throw FormAlreadySignedException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return "The grade is too high";
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return "The grade is too low";
}

const char *Form::FormAlreadySignedException::what() const noexcept
{
	return "The form has already been signed";
}

Form::~Form()
{
}

void Form::_checkGrade(unsigned char grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	return (stream << "The form " << form.getName() << ":" << std::endl << "Grade to sign: " << (int)form.getGradeSign() << std::endl << "Grade to exec: " << (int)form.getGradeExec() << std::endl << "Has been signed: " << (form.getIsSigned() ? "Yes" : "no"));
}
