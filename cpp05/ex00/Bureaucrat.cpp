#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, unsigned char grade) : _name(name)
{
	_checkGrade(grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

void Bureaucrat::_checkGrade(unsigned char grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::promote()
{
	_checkGrade(_grade - 1);
	_grade--;
}

void Bureaucrat::demote()
{
	_checkGrade(_grade + 1);
	_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "The grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "The grade is too high";
}

std::string Bureaucrat::getName() const
{
	return _name;
}

unsigned char Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &bureaucrat)
{
	outstream << bureaucrat.getName() << ", bureaucrat grade " << (int)bureaucrat.getGrade();
	return outstream;
}
