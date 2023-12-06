/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:05:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 19:03:58 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	test1("Billy");
	ClapTrap	test2("Tom");
	ScavTrap	test3("Jack");

	std::cout << std::endl;
	test2.setDmg(2);
	test1.attack("Tom");
	test2.takeDamage(20);
	test2.beRepaired(1);
	std::cout << std::endl;

	test3.attack("Billy");
	test1.takeDamage(20);
	test1.attack("Jack");
	test3.takeDamage(20);
	std::cout << std::endl;

	test1.attack("Jack");
	test3.takeDamage(20);
	test3.attack("Billy");
	test1.takeDamage(20);
	std::cout << std::endl;

	test3.beRepaired(10);
	test1.attack("Jack");
	test3.takeDamage(20);
	std::cout << std::endl;

	test3.attack("Billy");

	test1.takeDamage(20);
	test1.attack("Jack");
	test3.takeDamage(20);
	test1.attack("Jack");
	test3.takeDamage(20);
	test1.attack("Jack");
	test3.takeDamage(20);
	test1.attack("Jack");
	test3.takeDamage(20);
	test3.beRepaired(100);
	test1.guardGate();
	std::cout << std::endl;

	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.attack("random Claptraps");
	test1.beRepaired(20);
	std::cout << std::endl;
}