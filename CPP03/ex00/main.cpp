/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:05:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 17:32:48 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	test1("Billy");
	ClapTrap	test2("Tom");

	std::cout << std::endl;
	test1.setDmg(3);
	test2.setDmg(2);
	test1.attack("Tom");
	test2.takeDamage(3);
	test2.beRepaired(1);
	std::cout << std::endl;

	test2.attack("Billy");
	test1.takeDamage(2);
	test1.attack("Tom");
	test2.takeDamage(3);
	std::cout << std::endl;

	test1.attack("Tom");
	test2.takeDamage(3);
	test2.attack("Billy");
	test1.takeDamage(2);
	std::cout << std::endl;

	test2.beRepaired(1);
	test1.attack("Tom");
	test2.takeDamage(3);
	std::cout << std::endl;

	test2.attack("Billy");
	test2.beRepaired(10);
	test1.attack("Tom");
	test2.takeDamage(3);
	std::cout << std::endl;

	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.beRepaired(3);
	std::cout << std::endl;
}