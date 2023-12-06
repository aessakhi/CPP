/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:35:27 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/08 23:39:02 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*zombie_horde;
	int	i;

	i = 0;
	zombie_horde = zombieHorde(15, "Random Zombie");
	while (i < 15)
	{
		std::cout << "Zombie " << i + 1 << std::endl;
		zombie_horde[i].announce();
		i++;
	}
	delete [] zombie_horde;
}