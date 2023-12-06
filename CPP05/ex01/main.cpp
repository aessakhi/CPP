/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:06:48 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 01:30:25 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat *boss = new Bureaucrat("Boss", 1);
	Bureaucrat *employee = new Bureaucrat("Employee", 13);
	Bureaucrat *new_hire = new Bureaucrat("New Hire", 30);
	std::cout << std::endl;

	Form *form = new Form("Form 12", 12, 25);
	std::cout << *form << std::endl;
	std::cout << std::endl;

	new_hire->signForm(*form);
	form->beSigned(*new_hire);
	std::cout << std::endl;

	std::cout << *form << std::endl;
	std::cout << std::endl;
	
	employee->signForm(*form);
	form->beSigned(*employee);
	std::cout << std::endl;

	std::cout << *form << std::endl;
	std::cout << std::endl;

	boss->signForm(*form);
	form->beSigned(*boss);
	std::cout << std::endl;

	std::cout << *form << std::endl;
	std::cout << std::endl;

	delete boss;
	delete employee;
	delete form;
	delete new_hire;
}