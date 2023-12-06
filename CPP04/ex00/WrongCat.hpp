/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:17:15 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/17 16:18:42 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat:	public WrongAnimal
{
public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(WrongCat const & src);

	WrongCat	&operator=(WrongCat const & rhs);
	void	makeSound() const;
};

#endif