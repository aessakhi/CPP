/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:14:33 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/17 16:03:33 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Random Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	this->type = src.type;
}

Animal	&Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Random sound" << std::endl;
}

const std::string	Animal::getType() const
{
	return (this->type);
}