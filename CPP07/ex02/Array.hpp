/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:15:26 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 00:24:37 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>
#include <iostream>

template<typename T>
class Array
{
public:
	Array<T>()
	{
		this->_size = 0;
		this->_array = new T[0];
	}
	Array<T>(unsigned int i)
	{
		this->_size = i;
		this->_array = new T[i];
	}
	Array<T>(Array const &src)
	{
		this->_size = src.size();
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = src._array[i];
	}
	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			if (this->_array)
				delete [] this->_array;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = rhs._array[i];
		}
		return (*this);
	}
	T &operator[](unsigned int const &i)
	{
		if (i >= this->_size)
			throw OutOfRange();
		return (this->_array[i]);
	}
	T &operator[](unsigned int const &i) const
	{
		if (i >= this->_size)
			throw OutOfRange();
		return (this->_array[i]);
	}
	~Array(){delete [] this->_array;}

	unsigned int	size() const{return (this->_size);}
private:
	unsigned int _size;
	T	*_array;

class OutOfRange: public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Value out of range";
			}
	};
};

#endif