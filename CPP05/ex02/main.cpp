/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:06:48 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 01:32:46 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	Bureaucrat *boss = new Bureaucrat("Boss", 1);
	Bureaucrat *employee = new Bureaucrat("Employee 1", 26);
	Bureaucrat *employee_2 = new Bureaucrat("Employee 2", 72);
	Bureaucrat *new_hire = new Bureaucrat("New Hire", 145);
	PresidentialPardonForm	*form = new PresidentialPardonForm("Mr. Random");
	RobotomyRequestForm		*robotomy = new RobotomyRequestForm("Mr. Roboto");
	ShrubberyCreationForm	*shrubbery = new ShrubberyCreationForm("Garden");
	std::cout << std::endl;

	std::cout << "TEST FOR SHRUBBERY" << std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << std::endl;

	employee_2->executeForm(*shrubbery);
	new_hire->signForm(*shrubbery);
	shrubbery->beSigned(*new_hire);
	new_hire->executeForm(*shrubbery);
	std::cout << std::endl;
	employee_2->signForm(*shrubbery);
	shrubbery->beSigned(*employee_2);
	employee_2->executeForm(*shrubbery);
	std::cout << std::endl;

	std::cout << "TEST FOR ROBOTOMY" << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << std::endl;

	new_hire->signForm(*robotomy);
	robotomy->beSigned(*new_hire);
	new_hire->executeForm(*robotomy);
	std::cout << std::endl;
	employee->executeForm(*robotomy);
	employee_2->signForm(*robotomy);
	robotomy->beSigned(*employee_2);
	employee_2->executeForm(*robotomy);
	employee->signForm(*robotomy);
	employee->executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << "TEST FOR PRESIDENTIAL PARDON" << std::endl;
	std::cout << *form << std::endl;
	std::cout << std::endl;

	boss->executeForm(*form);
	new_hire->signForm(*form);
	form->beSigned(*new_hire);
	new_hire->executeForm(*form);
	std::cout << std::endl;
	employee->executeForm(*form);
	employee_2->signForm(*form);
	form->beSigned(*employee_2);
	employee_2->executeForm(*form);
	employee->signForm(*form);
	employee->executeForm(*form);
	std::cout << std::endl;
	boss->signForm(*form);
	form->beSigned(*boss);
	boss->executeForm(*form);

	std::cout << std::endl;
	delete boss;
	delete employee;
	delete employee_2;
	delete new_hire;
	delete form;
	delete robotomy;
	delete shrubbery;
}