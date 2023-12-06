/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:47:19 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/11 22:57:17 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const & src);
	~Fixed();
	Fixed &operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					_fixed_value;
	static const int	_bits = 8;
};

#endif