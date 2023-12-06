/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:31:32 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/27 17:11:32 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_dmg = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_dmg = src._dmg;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const & rhs)
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

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hp == 0)
	{
		std::cout << "ScavTrap" << this->_name << " is too dead to attack!" << std::endl;
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << "ScavTrap" << this->_name << " is too tired to attack!" << std::endl;
		return ;
	}
	this->_ep--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg << " points of damage!";
	std::cout << " (" << this->_ep << " energy remaining)" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hp == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't enter Guard Mode!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is in Guard Mode!" << std::endl;
}
