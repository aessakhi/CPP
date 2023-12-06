/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:13:46 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/18 16:18:09 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(Animal const & src);

	Animal	&operator=(Animal const & rhs);
	virtual void	makeSound() const;
	const std::string	getType() const;
protected:
	std::string	type;
};

#endif