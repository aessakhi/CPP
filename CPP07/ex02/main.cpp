/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:39:45 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 15:30:48 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

class Test
{
public:
	Test(){};
	Test(int value): _value(value){};
	~Test(){};
	bool	operator<(Test const &rhs) const;
	bool	operator<=(Test const &rhs) const;
	bool	operator>(Test const &rhs) const;
	bool	operator>=(Test const &rhs) const;
	Test	&operator=(Test const &rhs);
	int	getValue() const{return (this->_value);}
	void	setValue(const int value){this->_value = value;};
private:
	int	_value;
};

Test	&Test::operator=(Test const &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getValue();
	return (*this);
}

bool	Test::operator<(Test const &rhs) const
{
	return (this->_value < rhs.getValue());
}

bool	Test::operator<=(Test const &rhs) const
{
	return (this->_value <= rhs.getValue());
}

bool	Test::operator>(Test const &rhs) const
{
	return (this->_value > rhs.getValue());
}

bool	Test::operator>=(Test const &rhs) const
{
	return (this->_value >= rhs.getValue());
}

std::ostream &operator<<(std::ostream & o, Test const & i)
{
	o << i.getValue();
	return (o);
}

int	main()
{
	std::cout << "TEST WITH INT" << std::endl;
	Array	<int>zero;
	std::cout << zero.size() << std::endl;
	Array	<int>ten(10);
	std::cout << ten.size() << std::endl;
	try
	{
		ten[-11] = 32;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << ten[0] << std::endl;
	for (size_t i = 0; i < 10; i++)
		ten[i] = i;
	std::cout << "Original array = {";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ten[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Size = " << ten.size() << std::endl;
	std::cout << "TEST COPY CONSTRUCTOR" << std::endl;
	Array <int>cpy(ten);
	for (size_t i = 0; i < 10; i++)
		ten[i] = ten[i] + 10;
	std::cout << "Original array = {";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ten[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;;
	std::cout << "Copy array = {";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << cpy[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST ASSIGNMENT OPERATOR" << std::endl;
	cpy = ten;
	std::cout << "Original array = {";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << ten[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Array after assignment = {";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << cpy[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST WITH STR" << std::endl;
	Array <std::string>str(5);
	std::cout << str.size() << std::endl;
	for (size_t i = 0; i < 5; i++)
		str[i] = "Test";
	std::cout << "Original array = {";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << str[i];
		if (i != 4)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST WITH CLASS" << std::endl;
	Array <Test>tests(5);
	try
	{
	for (size_t i = 0; i < 7; i++)
		tests[i].setValue(i);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Check value inside array of test" << std::endl;
	std::cout << "Original array of class Test = {";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << tests[i];
		if (i != 4)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}
