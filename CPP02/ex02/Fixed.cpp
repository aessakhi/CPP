/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:52:16 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/27 15:48:28 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixed_value(0)
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int nb)
{
	this->_fixed_value = nb << this->_bits;
}

Fixed::Fixed(const float nb)
{
	this->_fixed_value = (int)roundf(nb * (1 << this->_bits));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixed_value = rhs.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits(this->_fixed_value + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	result;
	result.setRawBits(this->_fixed_value - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits(this->_fixed_value * rhs.getRawBits() >> this->_bits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits(this->_fixed_value / rhs.getRawBits() << this->_bits);
	return (result);
}

Fixed	&Fixed::operator++()
{
	this->_fixed_value = this->_fixed_value + ((int)roundf(0.00390625 * (1 << this->_bits)));
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;

	tmp = *this;
	this->_fixed_value = this->_fixed_value + ((int)roundf(0.00390625 * (1 << this->_bits)));
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_fixed_value = this->_fixed_value - ((int)roundf(0.00390625 * (1 << this->_bits)));
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp;

	tmp = *this;
	this->_fixed_value = this->_fixed_value - ((int)roundf(0.00390625 * (1 << this->_bits)));
	return (tmp);
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

int	Fixed::getRawBits(void)	const
{
	return (this->_fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_value / (1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixed_value >> this->_bits);
}

Fixed	&Fixed::min(Fixed &first_n, Fixed &second_n)
{
	if (first_n.getRawBits() < second_n.getRawBits())
		return (first_n);
	else
		return (second_n);
}

Fixed	&Fixed::max(Fixed &first_n, Fixed &second_n)
{
	if (first_n.getRawBits() > second_n.getRawBits())
		return (first_n);
	else
		return (second_n);
}

Fixed	&Fixed::min(Fixed const &first_n, Fixed const &second_n)
{
	static Fixed	tmp;
	
	if (first_n.getRawBits() < second_n.getRawBits())
	{
		tmp.setRawBits(first_n.getRawBits());
		return (tmp);
	}
	else
	{
		tmp.setRawBits(second_n.getRawBits());
		return (tmp);
	}
}

Fixed	&Fixed::max(Fixed const &first_n, Fixed const &second_n)
{
	static Fixed	tmp;
	
	if (first_n.getRawBits() > second_n.getRawBits())
	{
		tmp.setRawBits(first_n.getRawBits());
		return (tmp);
	}
	else
	{
		tmp.setRawBits(second_n.getRawBits());
		return (tmp);
	}
}

std::ostream & operator <<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}
