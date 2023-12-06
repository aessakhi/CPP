/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:51:50 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/30 17:31:35 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(const std::string str): _str(str)
{
}

Convert::~Convert()
{
}

Convert::Convert(Convert const &src)
{
	*this = src;
}

Convert	&Convert::operator=(Convert const &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

bool	isFloat(const std::string str)
{
	float f;
	std::string	new_str;

	if (str[str.size() - 1] != 'f')
		return (false);
	new_str = str;
	new_str.erase(new_str.size() - 1);
	std::istringstream iss(new_str);
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool	isDouble(const std::string str)
{
	std::istringstream iss(str);
	double d;

	iss >> std::noskipws >> d;
	return iss.eof() && !iss.fail();
}

bool	isInt(const std::string str)
{
	std::istringstream iss(str);
	int i;

	iss >> std::noskipws >> i;
	return iss.eof() && !iss.fail();
}

const std::string	Convert::getType(void)
{
	return (this->_type);
}

void	Convert::startConvert(void)
{
	if (this->_str.length() == 1 && this->_str.find_first_of("0123456789") == std::string::npos)
	{
		this->_type = "char";
		this->toChar();
		return ;
	}
	else if (isInt(this->_str) == true)
	{
		this->_type = "int";
		this->toInt();
		return ;
	}
	else if (this->_str == "+inff" || this->_str == "-inff" || this->_str == "nanf" || isFloat(this->_str) == true)
	{
		this->_type = "float";
		this->toFloat();
		return ;
	}
	else if (this->_str == "+inf" || this->_str == "-inf" || this->_str == "nan" || isDouble(this->_str) == true)
	{
		this->_type = "double";
		this->toDouble();
		this->convertDouble();
		return ;
	}
	else
	{
		std::cout << "Type unknown: Input a char, int, float (+inff, -inff, nanf supported) or double (+inf, -inf, nan supported)" << std::endl;
		return ;
	}
}

void	Convert::toChar(void)
{
	this->_char = this->_str[0];
	std::cout << "char: '" << this->_char << "'" << std::endl;
	this->convertInt();
	this->convertFloat();
	this->convertDouble();
}

void	Convert::toFloat(void)
{
	this->_float = strtof(this->_str.c_str(), 0);
	this->convertChar();
	this->convertInt();
	std::cout << "float: " << this->_float;
	if (this->_str == "nanf" || this->_str == "+inff" || this->_str == "-inff")
		std::cout << "f" << std::endl;
	else
		std::cout << ".0f" << std::endl;
	this->convertDouble();
}

void	Convert::toDouble(void)
{
	this->_double = strtod(this->_str.c_str(), 0);
	this->convertChar();
	this->convertInt();
	this->convertFloat();
	std::cout << "double: " << this->_double;
	if (this->_str == "nan" || this->_str == "+inf" || this->_str == "-inf")
		std::cout << std::endl;
	else
		std::cout << ".0" << std::endl;
}

void	Convert::toInt(void)
{
	std::istringstream iss(this->_str);
	int i;

	iss >> std::noskipws >> i;
	this->_int = i;
	this->convertChar();
	std::cout << "int: " << this->_int << std::endl;
	this->convertFloat();
	this->convertDouble();
}

void	Convert::convertChar(void)
{
	if (this->_type == "int")
	{
		if (this->_int < 0 || this->_int > 255)
		{
			std::cout << "char: Impossible" << std::endl;
			return ;
		}
		this->_char = static_cast<char>(this->_int);
		if (isprint(this->_char))
			std::cout << "char: '" << this->_char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (this->_type == "float")
	{
		if (this->_str == "nanf" || this->_str == "+inff" || this->_str == "-inff"
		|| this->_float < 0 || this->_float > 255)
		{
			std::cout << "char: Impossible" << std::endl;
			return ;
		}
		this->_char = static_cast<char>(this->_float);
		if (isprint(this->_char))
			std::cout << "char: '" << this->_char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (this->_type == "double")
	{
		if (this->_str == "nan" || this->_str == "+inf" || this->_str == "-inf"
		|| this->_double < 0 || this->_double > 255)
		{
			std::cout << "char: Impossible" << std::endl;
			return ;
		}
		this->_char = static_cast<char>(this->_double);
		if (isprint(this->_char))
			std::cout << "char: '" << this->_char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void	Convert::convertFloat(void)
{
	if (this->_type == "char")
	{
		this->_float = static_cast<float>(this->_char);
		std::cout << "float: " << this->_float << ".0f" << std::endl;
		return ;
	}
	else if (this->_type == "int")
	{
		this->_float = static_cast<float>(this->_int);
		std::cout << "float: " << this->_float << ".0f" << std::endl;
		return ;
	}
	else if (this->_type == "double")
	{
		this->_float = static_cast<float>(this->_double);
		std::cout << "float: " << this->_float;
		if (this->_str == "nan" || this->_str == "+inf" || this->_str == "-inf"
		|| this->_double > __FLT_MAX__ || this->_double < __FLT_MIN__)
			std::cout << "f" << std::endl;
		else
			std::cout << ".0f" << std::endl;
		return ;
	}
}

void	Convert::convertDouble(void)
{
	if (this->_type == "char")
	{
		this->_double = static_cast<double>(this->_char);
		std::cout << "double: " << this->_double << ".0" << std::endl;
		return ;
	}
	else if (this->_type == "int")
	{
		this->_double = static_cast<double>(this->_int);
		std::cout << "double: " << this->_double << ".0" << std::endl;
		return ;
	}
	else if (this->_type == "float")
	{
		this->_double = static_cast<double>(this->_float);
		std::cout << "double: " << this->_double;
		if (this->_str == "nanf" || this->_str == "+inff" || this->_str == "-inff")
			std::cout << std::endl;
		else
			std::cout << ".0" << std::endl;
		return ;
	}
}

void	Convert::convertInt(void)
{
	if (this->_type == "char")
	{
		this->_int = static_cast<int>(this->_char);
		std::cout << "int: " << this->_int << std::endl;
		return ;
	}
	else if (this->_type == "double")
	{
		if (this->_str == "nan" || this->_str == "+inf" || this->_str == "-inf"
		|| this->_double > (2147483647) || this->_double < (-2147483648))
		{
			std::cout << "int: Impossible" << std::endl;
			return ;
		}
		this->_int = static_cast<int>(this->_double);
		std::cout << "int: " << this->_int << std::endl;
		return ;
	}
	else if (this->_type == "float")
	{
		if (this->_str == "nanf" || this->_str == "+inff" || this->_str == "-inff"
		|| this->_float > (2147483647.0f) || this->_float < (-2147483648.0f))
		{
			std::cout << "int: Impossible" << std::endl;
			return ;
		}
		this->_int = static_cast<int>(this->_float);
		std::cout << "int: " << this->_int << std::endl;
		return ;
	}
}
