/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:17:43 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 17:23:47 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

class ItemNotFoundException: public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Item was not found in the array");
	}
};

template <typename T>
void	easyfind(T &x, const int &item)
{
	typename T::iterator i;

	i = std::find(x.begin(), x.end(), item);
	if (i != x.end())
		std::cout << "Item was found at position " << std::distance(x.begin(), i) << std::endl;
	else
		throw ItemNotFoundException();
}

#endif