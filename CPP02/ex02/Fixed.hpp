/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/14 13:55:41 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(Fixed const & src);
	~Fixed();
	
	Fixed	&operator=(Fixed const & rhs);
	
	Fixed	operator+(Fixed const & rhs);
	Fixed	operator-(Fixed const & rhs);
	Fixed	operator*(Fixed const & rhs);
	Fixed	operator/(Fixed const & rhs);

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	bool	operator>(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static	Fixed &min(Fixed &first_n, Fixed &second_n);
	static	Fixed &min(Fixed const &first_n, Fixed const &second_n);
	static	Fixed &max(Fixed &first_n, Fixed &second_n);
	static	Fixed &max(Fixed const &first_n, Fixed const &second_n);
private:
	int					_fixed_value;
	static const int	_bits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif