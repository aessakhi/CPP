/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:08:02 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 20:28:00 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
#include <algorithm>

class Span
{
public:
	Span(): _size(0){};
	Span(unsigned int N);
	Span(Span const &src);
	Span	&operator=(Span const &rhs);
	~Span();

	void	addNumber(const int &nb);
	void	addNumbers(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	long int		shortestSpan() const;
	long int		longestSpan() const;
	std::vector<int> const &getVector() const;
private:
	std::vector<int>	_vector;
	unsigned int _size;

class SpanNotEnoughNbException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Not enough numbers to execute that function");
		}
};

class SpanFullException: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Span is full, can't add new numbers");
		}
};
};

#endif