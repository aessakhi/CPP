/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:05:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/17 14:59:17 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondtrap("Diamond");
	std::cout << "HP = " << diamondtrap.getHp() << std::endl;
	std::cout << "EP = " << diamondtrap.getEp() << std::endl;
	std::cout << "DMG = " << diamondtrap.getDmg() << std::endl;
	diamondtrap.whoAmI();
	diamondtrap.attack("Billy");
}