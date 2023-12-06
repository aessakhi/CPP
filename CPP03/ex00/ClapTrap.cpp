/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:38:26 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 18:56:56 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	this->_name = src._name;
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_dmg = src._dmg;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & rhs)
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

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too dead to attack!" << std::endl;
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too tired to attack!" << std::endl;
		return ;
	}
	this->_ep--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg << " points of damage!";
	std::cout << " (" << this->_ep << " energy remaining)" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " is already dead!" << std::endl;
		return ;
	}
	this->_hp = this->_hp - amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << this->_name << " takes " << amount << " damage! ";
	if (this->_hp == 0)
		std::cout << this->_name << " is down!" << std::endl;
	else
		std::cout << "(" << this->_hp << " HP remaining)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << this->_name << " is too dead to repair itself!" << std::endl;
		return ;
	}
	if (this->_ep == 0)
	{
		std::cout << this->_name << " doesn't have enough energy to repair itself!" << std::endl;
		return ;
	}
	this->_hp = this->_hp + amount;
	this->_ep--;
	std::cout << this->_name << " repairs itself for " << amount << " HP !";
	std::cout << " (" << this->_hp << " HP remaining, " << this->_ep << " energy remaining)" << std::endl;
}

std::string	ClapTrap::getName()
{
	return(this->_name);
}

int	ClapTrap::getHp()
{
	return(this->_hp);
}

int	ClapTrap::getEp()
{
	return(this->_ep);
}

int	ClapTrap::getDmg()
{
	return(this->_dmg);
}

void	ClapTrap::setName(const std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHp(const unsigned int hp)
{
	this->_hp = hp;
}

void	ClapTrap::setEp(const unsigned int ep)
{
	this->_ep = ep;
}

void	ClapTrap::setDmg(const unsigned int dmg)
{
	this->_dmg = dmg;
}