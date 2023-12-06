/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:54:36 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/29 21:17:42 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, size_t const &size, void (*func)(T &))
{
	for (size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

template<typename T>
void	iter(T *array, size_t const &size, void (*func)(T const &))
{
	for (size_t i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

#endif