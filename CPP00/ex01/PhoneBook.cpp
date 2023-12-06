/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:24:17 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/05 20:39:58 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed, contacts erased" << std::endl; 
	return ;
}

void	PhoneBook::add_contact(const int	n_of_contacts)
{
	if (n_of_contacts > 7)
	{
		if (this->oldest_entry > 7)
			this->oldest_entry = 0;
		this->contact[oldest_entry].replace_contact();
		this->oldest_entry++;
	}
	else
	{
		if (n_of_contacts == 0)
			this->oldest_entry = 0;
		this->contact[n_of_contacts].fill_contact();
	}
	return ;
}

void	create_column(void)
{
	std::cout << std::setw(10);
	std::cout << "ID";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << "NICKNAME";
	std::cout << std::endl;
}

void	PhoneBook::search_contact(const int	n_of_contacts)
{
	int	i;
	std::string	id;

	i = 0;
	create_column();
	if (n_of_contacts == 0)
		return ;
	else
	{
		while (i < n_of_contacts)
		{
			this->contact[i].display_column(i);
			i++;
		}
		i = 0;
		while (i <= 0 || i > n_of_contacts)
		{
			if (i < 0 || i > n_of_contacts)
				std::cout << "Invalid ID" << std::endl;
			if (n_of_contacts == 1)
				std::cout << "Enter the ID of the contact (1) to get more information: ";
			else
				std::cout << "Enter the ID of a contact (1 to " << n_of_contacts << ") to get more information: ";
			if (!std::getline(std::cin, id))
				break;
			std::istringstream(id) >> i;
		}
		i = i - 1;
		this->contact[i].display_contact();
	}
	return ;
}