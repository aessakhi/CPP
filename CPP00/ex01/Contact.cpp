/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:16:17 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/05 20:39:37 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string	trim(std::string str)
{
	std::string	result;
	std::size_t	start;
	std::size_t	end;

	start = str.find_first_not_of(' ');
	if (start == std::string::npos)
	{
		result = "";
		return (result);
	}
	end = str.find_last_not_of(' ');
	result = str.substr(start, end - start + 1);
	return (result);
}

std::string	check_valid_number(std::string str)
{
	std::size_t	found;

	found = str.find_first_not_of("0123456789+- /()");
	if (found != std::string::npos)
	{
		std::cout << "Invalid phone number" << std::endl;
		str = "";
	}
	return (str);
}

void	Contact::fill_contact(void)
{
	while(this->_first_name.compare("") == 0)
	{
		std::cout << "Enter the first name of the new contact: ";
		if (!std::getline(std::cin, this->_first_name))
			break;
		this->_first_name = trim(this->_first_name);
	}
	while(this->_last_name.compare("") == 0)
	{
		std::cout << "Enter the last name of the new contact: ";
		if (!std::getline(std::cin, this->_last_name))
			break;
		this->_last_name = trim(this->_last_name);
	}
	while(this->_nickname.compare("") == 0)
	{
		std::cout << "Enter the nickname of the new contact: ";
		if (!std::getline(std::cin, this->_nickname))
			break;
		this->_nickname = trim(this->_nickname);
	}
	while(this->_phone_number.compare("") == 0)
	{
		std::cout << "Enter the phone number of the new contact: ";
		if (!std::getline(std::cin, this->_phone_number))
			break;
		this->_phone_number = trim(this->_phone_number);
		this->_phone_number = check_valid_number(this->_phone_number);
	}
	while(this->_darkest_secret.compare("") == 0)
	{
		std::cout << "Enter the darkest secret of the new contact: ";
		if (!std::getline(std::cin, this->_darkest_secret))
			break;
		this->_darkest_secret = trim(this->_darkest_secret);
	}
}

void	Contact::display_contact(void)
{
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
	return ;
}

std::string	shrink_data(std::string str)
{
	std::string	result;

	result = str;
	if (result.length() > 10)
	{
		result.resize(10);
		result[9] = '.';
	}
	return (result);
}

void	Contact::display_column(const int n)
{
	std::cout << std::setw(10);
	std::cout << n + 1;
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << shrink_data(this->_first_name);
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << shrink_data(this->_last_name);
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << shrink_data(this->_nickname);
	std::cout << std::endl;
}

void	Contact::replace_contact()
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	Contact::fill_contact();
}