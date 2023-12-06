/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:29:21 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/27 23:49:27 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main()
{
	Animal *animals[6];
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;

	//Deep copy Objets restent distincts | Shallow copy Referencent la meme chose
	Dog dog(*(Dog*)animals[2]);
	for (int i = 0; i < 100; i++)
		(*(Dog*)animals[2]).getBrain()->setIdea("New idea", i);
	std::cout << "ORIGINAL DOG " << (*(Dog*)animals[2]).getBrain()->getIdea(43) << std::endl;
	std::cout << "COPY DOG " << dog.getBrain()->getIdea(43) << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete animals[i];
	std::cout << std::endl;
}