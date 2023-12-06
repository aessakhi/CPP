/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:08:37 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/18 19:05:22 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &src);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	const std::string	getName() const;
	int	getGrade() const;
	
	void	increaseGrade();
	void	decreaseGrade();
private:
	const std::string _name;
	int	_grade;

class GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
};

class GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too low");
		}
};
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const & i);

#endif