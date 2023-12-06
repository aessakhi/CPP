/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:26:58 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 14:44:38 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

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
	int	a = 45;
	int	b = 20;
	
	std::cout << "TEST WITH INT" << std::endl;
	std::cout << "a is equal to " << a << std::endl;
	std::cout << "b is equal to " << b << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << min(a, b) << std::endl;
	swap(a , b);
	std::cout << "After swap, a is equal to " << a << std::endl;
	std::cout << "After swap, b is equal to " << b << std::endl;
	std::cout << std::endl;

	char c = 'a';
	char d = 'o';
	std::cout << "TEST WITH CHAR" << std::endl;
	std::cout << "c is equal to " << c << std::endl;
	std::cout << "d is equal to " << d << std::endl;
	std::cout << max(c, d) << std::endl;
	std::cout << min(c, d) << std::endl;
	swap(c , d);
	std::cout << "After swap, c is equal to " << c << std::endl;
	std::cout << "After swap, d is equal to " << d << std::endl;

	std::string str_1 = "lmao";
	std::string str_2 = "yoooo";
	std::cout << "TEST WITH STRING" << std::endl;
	std::cout << "Before swap, str_1 is equal to " << str_1 << std::endl;
	std::cout << "Before swap, str_2 is equal to " << str_2 << std::endl;
	swap(str_1 , str_2);
	std::cout << "After swap, str_1 is equal to " << str_1 << std::endl;
	std::cout << "After swap, str_2 is equal to " << str_2 << std::endl;
	std::cout << std::endl;

	Test test1(32);
	Test test2(78);
	std::cout << "TEST WITH CLASS" << std::endl;
	std::cout << "Before swap, value in test1 is " << test1.getValue() << std::endl;
	std::cout << "Before swap, value in test2 is " << test2.getValue() << std::endl;
	std::cout << max(test1, test2) << std::endl;
	std::cout << min(test1, test2) << std::endl;
	swap(test1, test2);
	std::cout << "After swap, value in test1 is " << test1.getValue() << std::endl;
	std::cout << "After swap, value in test2 is " << test2.getValue() << std::endl;
}

/* int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
 */
