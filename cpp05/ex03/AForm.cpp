#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeSign(150), _gradeExec(150), _target("unset")
{}

AForm::AForm(std::string name, unsigned char gradeSign, unsigned char gradeExec, std::string target) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec), _target(target)
{
	_checkGrade(gradeSign);
	_checkGrade(gradeExec);
}

AForm::AForm(AForm &other) : _name(other._name), _isSigned(false), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
}

std::string AForm::getTarget() const
{
	return _target;
}

void AForm::setTarget(std::string target)
{
	_target = target;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

unsigned char AForm::getGradeSign() const
{
	return _gradeSign;
}

unsigned char AForm::getGradeExec() const
{
	return _gradeExec;
}

void AForm::beSigned(Bureaucrat &signee)
{
	if (signee.getGrade() > _gradeSign)
		throw GradeTooLowException();
	if (_isSigned)
		throw AFormAlreadySignedException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return "The grade is too high";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "The grade is too low";
}

const char *AForm::AFormAlreadySignedException::what() const noexcept
{
	return "The form has already been signed";
}

const char *AForm::AFormNotSignedException::what() const noexcept
{
	return "The form has not been signed yet";
}

AForm::~AForm()
{
}

void AForm::_checkGrade(unsigned char grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw AFormNotSignedException();
	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();
	_execute();
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
	return (stream << "The form " << form.getName() << ":" << std::endl << "Grade to sign: " << (int)form.getGradeSign() << std::endl << "Grade to exec: " << (int)form.getGradeExec() << std::endl << "Has been signed: " << (form.getIsSigned() ? "Yes" : "no"));
}
