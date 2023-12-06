/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:33:08 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/05 20:38:26 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	std::string	line;
	PhoneBook	phonebook;
	int	n_of_contacts;

	n_of_contacts = 0;
	while (1)
	{
		std::cout << "Type ADD to add a new contact, SEARCH to display the list of contacts, EXIT to quit: ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			break;
		}
		if (line.compare("ADD") == 0)
		{
			phonebook.add_contact(n_of_contacts);
			if (n_of_contacts < 8)
				n_of_contacts++;
		}
		else if (line.compare("SEARCH") == 0)
			phonebook.search_contact(n_of_contacts);
		else if (line.compare("EXIT") == 0)
			return (0);
		else
			std::cout << line << "is not a valid command" << std::endl;
	}
	return (0);
}