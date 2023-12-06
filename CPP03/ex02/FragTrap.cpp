/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:18:44 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/27 17:06:09 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_dmg = 30;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_dmg = src._dmg;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)

	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_dmg = rhs._dmg;
	}
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (this->_hp == 0)
	{
		std::cout << "Fragtrap " << this->_name << " can't high five, it's dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " raises his hand for a high five!" << std::endl;
}
