/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:39 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 22:25:18 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->_size = N;
}

Span::Span(Span const &src)
{
	this->_size = src._size;
	this->_vector = src.getVector();
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_vector = rhs.getVector();
	}
	return (*this);
}

Span::~Span()
{
}

std::vector<int> const	&Span::getVector() const
{
	return (_vector);
}

void	Span::addNumber(const int &nb)
{
	if (this->_vector.size() >= this->_size)
		throw(SpanFullException());
	this->_vector.push_back(nb);
}

void	Span::addNumbers(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	if (std::distance(begin, end) > this->_size)
		throw SpanFullException();
	this->_vector.insert(this->_vector.end(), begin, end);
}

long int	Span::shortestSpan() const
{
	if (this->_vector.size() <= 1)
		throw SpanNotEnoughNbException();
	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	long int minspan = (long int)tmp.back() - tmp.front();
	for (size_t i = 0; i < tmp.size() - 1; i++)
		for (size_t j = i + 1; j < tmp.size(); j++)
			if ((long int)tmp[j] - tmp[i] < minspan)
				minspan = (long int)tmp[j] - tmp[i];
	return (minspan);
}

long int	Span::longestSpan() const
{
	if (this->_vector.size() <= 1)
		throw SpanNotEnoughNbException();
	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	return ((long int )tmp.back() - tmp.front());
}