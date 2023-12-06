/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:51:39 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/18 19:23:49 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch(GradeTooHighException& e)
	{
		std::cerr << this->_name << ": " << e.what() << std::endl;
		grade = 1;
	}
	catch(GradeTooLowException& e)
	{
		std::cerr << this->_name << ": " << e.what() << std::endl;
		grade = 150;
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src._name), _grade(src._grade)
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

void	Bureaucrat::increaseGrade()
{
	try
	{
		if (this->_grade - 1 < 1)
		{
			throw GradeTooHighException();
		}
		if (this->_grade - 1 > 150)
		{
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << this->_name << ": " << e.what() << std::endl;
		return ;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << this->_name << ": " << e.what() << std::endl;
		return ;
	}
	this->_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	try
	{
		if (this->_grade + 1 < 1)
		{
			throw GradeTooHighException();
		}
		if (this->_grade + 1> 150)
		{
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << this->_name << ": " << e.what() << std::endl;
		return;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << this->_name << ": " << e.what() << std::endl;
		return ;
	}
	this->_grade++;
}
const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}