/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:13:22 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 00:36:05 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(const std::string name, int to_sign, int to_exec);
	~Form();
	Form(Form const &src);

	Form	&operator=(Form const &rhs);

	const std::string	getName() const;
	bool				getSigned() const;
	int					getToSign() const;
	int					getToExec() const;

	void	beSigned(const Bureaucrat &bureaucrat);
private:
	const std::string _name;
	bool	_signed;
	int	_to_sign;
	int	_to_exec;
class GradeTooHighException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Bureaucrat's grade is too high");
		}
};
class GradeTooLowException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Bureaucrat's grade is too low");
		}
};
};

std::ostream &operator<<(std::ostream & o, Form const & i);

#endif