/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:06:48 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 00:08:09 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat *boss = new Bureaucrat("Boss", 1);
	Bureaucrat *employee = new Bureaucrat("Employee", 150);
	std::cout << std::endl;

	std::cout << *boss << std::endl;
	std::cout << "INCREASE GRADE WHEN ALREADY AT MAX (1)" << std::endl;
	boss->increaseGrade();
	std::cout << *boss << std::endl;
	std::cout << std::endl;
	boss->decreaseGrade();
	std::cout << *boss << std::endl;
	boss->decreaseGrade();
	std::cout << *boss << std::endl;

	std::cout << std::endl;
	std::cout << *employee << std::endl;
	std::cout << "DECREASE GRADE WHEN ALREADY AT MIN (150)" << std::endl;
	employee->decreaseGrade();
	std::cout << *employee << std::endl;
	std::cout << std::endl;

	std::cout << *employee << std::endl;
	employee->increaseGrade();
	std::cout << *employee << std::endl;
	employee->increaseGrade();
	std::cout << *employee << std::endl;
	std::cout << std::endl;

	delete boss;
	delete employee;
}