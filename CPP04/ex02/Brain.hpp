/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:57:01 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/27 23:50:38 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	virtual ~Brain();
	Brain(Brain const & src);

	Brain	&operator=(Brain const & rhs);
	const std::string	&getIdea(int i) const;
	void	setIdea(const std::string, unsigned int i);
private:
	std::string	ideas[100];
};

#endif