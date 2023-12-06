/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:32:31 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 00:44:37 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int to_sign, int to_exec):	_name(name), _signed(false),
																			_to_sign(to_sign), _to_exec(to_exec)
{
}

Form::~Form()
{
}

Form::Form(Form const &src):	_name(src._name), _signed(src._signed),
								_to_sign(src._to_sign), _to_exec(src._to_exec)
{
}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return	(this->_signed);
}

int	Form::getToSign() const
{
	return (this->_to_sign);
}

int	Form::getToExec() const
{
	return (this->_to_exec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->getToSign())
		{
			throw GradeTooLowException();
		}
		if (this->_signed == true)
		{
			throw std::invalid_argument("Form was already signed");
		}
	}
	catch(GradeTooLowException& e)
	{
		std::cerr << this->_name << " couldn't be signed. Reason: " << bureaucrat.getName(); 
		std::cerr << " grade is too low (" << this->_to_sign << " lowest grade required)" << std::endl;
		return;
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << this->_name << " wasn't signed by " << bureaucrat.getName() << ". Reason: " << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " was signed by "<< bureaucrat.getName() << std::endl;
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form: " << i.getName() << std::endl;
	o << "Signed: ";
	if (i.getSigned() == true)
		o << "Yes";
	else
		o << "No";
	o << std::endl;
	o << "Lowest grade required to sign: " << i.getToSign() << std::endl;
	o << "Lowest grade required to execute: " << i.getToExec();
	return (o);
}