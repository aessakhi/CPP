/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:22:58 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/19 19:33:13 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

Form	*Intern::makeForm(const std::string name, const std::string target)
{
	int	i = 0;
	std::string	form[3] =
	{
		"Presidential pardon",
		"Shrubbery creation",
		"Robotomy request"
	};
	while (i < 3)
	{
		if (name.compare(form[i]) == 0)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		return (new PresidentialPardonForm(target));
	case 1:
		return (new ShrubberyCreationForm(target));
	case 2:
		return (new RobotomyRequestForm(target));
	default:
		std::cout << "Couldn't create form" << std::endl;
		break;
	}
	return (NULL);
}