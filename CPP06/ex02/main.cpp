/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:45:13 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/30 18:52:45 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base	*generate(void)
{
	srand(time(NULL));

	int randNum = (rand() % 3) + 1;
	if (randNum == 1)
	{	
		std::cout << "A created" << std::endl;
		return (new A());
	}
	else if (randNum == 2)
	{	
		std::cout << "B created" << std::endl;
		return (new B());
	}
	else if (randNum == 3)
	{	
		std::cout << "C created" << std::endl;
		return (new C());
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "Base is A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "Base is B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "Base is C" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	bool isA = true;
	bool isB = true;
	bool isC = true;

	try
	{
		Base a = dynamic_cast<A &>(p);
	}
	catch(std::exception &e)
	{
		isA = false;
	}
	try
	{
		Base b = dynamic_cast<B &>(p);
	}
	catch(std::exception &e)
	{
		isB = false;
	}
	try
	{
		Base c = dynamic_cast<C &>(p);
	}
	catch(std::exception &e)
	{
		isC = false;
	}
	if (isA == true)
		std::cout << "Base is A" << std::endl;
	else if (isB == true)
		std::cout << "Base is B" << std::endl;
	else if (isC == true)
		std::cout << "Base is C" << std::endl;
	return;
}

int main()
{
	Base *p = generate();
	Base &c = *p;
	identify(p);
	identify(c);
	delete p;
}
