/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:14:31 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 15:33:55 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	displayNb(int &i)
{
	std::cout << i << std::endl;
}

void	squareNb(int &i)
{
	i = i * i;
}

void	displayStr(std::string &str)
{
	std::cout << str << std::endl;
}

void	addtoStr(std::string &str)
{
	str = str + "_AFTER_ITER";
}

int	main()
{
	std::cout << "TEST WITH INT" << std::endl;
	int	array_of_int[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	iter(array_of_int, 10, displayNb);
	std::cout << std::endl;
	iter(array_of_int, 10, squareNb);
	iter(array_of_int, 10, displayNb);
	std::cout << std::endl;

	std::cout << "TEST WITH STRING" << std::endl;
	std::string array_of_str[5] = {"TEST1", "TEST2", "TEST3", "TEST4", "TEST5"};
	iter(array_of_str, 5, displayStr);
	std::cout << std::endl;
	iter(array_of_str, 2, addtoStr);
	iter(array_of_str, 5, displayStr);
}
