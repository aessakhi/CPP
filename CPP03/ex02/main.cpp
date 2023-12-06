/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:05:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 20:12:14 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap	test1("Billy");
	ClapTrap	test2("Tom");
	FragTrap	test3("Jack");

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

	test3.beRepaired(100);
	test3.highFivesGuys();
	test1.guardGate();
	std::cout << std::endl;
}