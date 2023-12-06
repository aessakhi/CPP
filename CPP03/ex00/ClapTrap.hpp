/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:37:51 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 17:31:01 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap();

	ClapTrap	&operator=(ClapTrap const & rhs);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName();
	int	getHp();
	int	getEp();
	int	getDmg();

	void	setName(const std::string name);
	void	setHp(const unsigned int	hp);
	void	setEp(const unsigned int	ep);
	void	setDmg(const unsigned int	dmg);
private:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_dmg;
};

#endif