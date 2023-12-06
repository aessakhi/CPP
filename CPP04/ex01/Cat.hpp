/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:25 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 16:27:42 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat:	public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(Cat const & src);

	Cat	&operator=(Cat const & rhs);
	void	makeSound() const;
	Brain	*getBrain(void) const;
private:
	Brain	*brain;
};

#endif
