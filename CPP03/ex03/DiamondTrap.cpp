/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:32:25 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 22:20:22 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap() 
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_hp = this->FragTrap::_hp;
	this->_ep = this->ScavTrap::_ep;
	this->_dmg = this->FragTrap::_dmg;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_dmg = FragTrap::_dmg;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_dmg = src._dmg;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const & rhs)
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

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap's name: " << this->_name << std::endl;
	std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}