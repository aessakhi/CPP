/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:58:13 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 01:00:08 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form("Robotomy request form", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form("Robotomy request form", 72, 45), _target(src._target)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

void	RobotomyRequestForm::execForm() const
{
	srand(time(NULL));

	int randNum = (rand() % 2) + 1;
	std::cout << "*DRILLING SOUNDS*" << std::endl;
	if (randNum == 1)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << this->_target << " avoided robotomy!" << std::endl;
}