/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:34:34 by aessakhi          #+#    #+#             */
/*   Updated: 2022/08/01 14:49:39 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
} */

int main()
{
	Span sp = Span(10);
	try
	{
		sp.addNumber(2147483647);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(23);
		sp.addNumber(39);
		sp.addNumber(78);
		sp.addNumber(152);
		sp.addNumber(-2147483648);
		sp.addNumber(13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
			std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Check copy constructor" << std::endl;
	Span sp2(sp);
	std::cout << std::endl;
	try
	{
			std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
			std::cout << "Longest span : " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Check assignment operator" << std::endl;
	Span sp3 = sp;
	std::cout << std::endl;
	try
	{
			std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
			std::cout << "Longest span : " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Check shortest and longest span with a size of 1" << std::endl;
	Span sizetest = Span(1);
	try
	{
		sizetest.addNumber(12);
		sizetest.addNumber(24);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Shortest span : " << sizetest.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span : " << sizetest.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Check addNumbers func + Huge value for size" << std::endl;
	Span huge(15000);
	std::vector<int> test;

	for (unsigned int i = 0; i < 15000; i++)
	{
		test.push_back(i);
	}
	try
	{
		huge.addNumbers(test.begin(), test.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Shortest span : " << huge.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span : " << huge.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
