/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:27:35 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/10 23:19:36 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie zombie("Classic Zombie");
	Zombie	*zombie2;

	zombie2 = newZombie("New Zombie");
	randomChump("Random Zombie");
	zombie.announce();
	(*zombie2).announce();
	delete zombie2;
}