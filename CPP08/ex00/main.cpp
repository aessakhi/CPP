/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:27:07 by aessakhi          #+#    #+#             */
/*   Updated: 2022/08/01 14:18:25 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int	main()
{
	std::cout << "TEST WITH VECTOR" << std::endl;

	std::vector<int> vector;
	vector.push_back(10);
	vector.push_back(45);
	vector.push_back(196);
	vector.push_back(78);
	vector.push_back(9865);
	vector.push_back(32);
	vector.push_back(7895);
	vector.push_back(123);
	try
	{
		std::cout << "Trying to find 123 (in the vector pos 7)" << std::endl;
		easyfind(vector, 123);
		std::cout << "Trying to find 57453 (not in the vector)" << std::endl;
		easyfind(vector, 57453);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "TEST WITH LIST" << std::endl;
	std::list<int> list;
	list.push_back(10);
	list.push_back(45);
	list.push_back(196);
	list.push_back(78);
	list.push_back(9865);
	list.push_back(10);
	list.push_back(7895);
	list.push_back(123);
	try
	{
		std::cout << "Trying to find 10 (in the list pos 0)" << std::endl;
		easyfind(list, 10);
		std::cout << "Trying to find 56945 (not in the list)" << std::endl;
		easyfind(list, 56945);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "TEST WITH DEQUE" << std::endl;
	std::deque<int> deque;
	deque.push_back(10);
	deque.push_back(45);
	deque.push_back(196);
	deque.push_back(78);
	deque.push_back(9865);
	deque.push_back(32);
	deque.push_back(7895);
	deque.push_back(123);
	try
	{
		std::cout << "Trying to find 7895 (in the deque pos 6)" << std::endl;
		easyfind(deque, 7895);
		std::cout << "Trying to find 3 (not in the deque)" << std::endl;
		easyfind(deque, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
