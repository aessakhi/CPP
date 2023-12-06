/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:44:26 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 18:39:55 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <limits>
#include <cctype>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>

class Convert
{
public:
	Convert(const std::string str);
	~Convert();

	Convert(Convert const &src);
	Convert	&operator=(Convert const &rhs);

	const std::string	getType(void);
	void	startConvert(void);
	void	convertFloat(void);
	void	convertInt(void);
	void	convertDouble(void);
	void	convertChar(void);
	void	toFloat(void);
	void	toInt(void);
	void	toDouble(void);
	void	toChar(void);
private:
	const std::string	_str;
	std::string			_type;
	int					_int;
	double				_double;
	float				_float;
	char				_char;
};

#endif
