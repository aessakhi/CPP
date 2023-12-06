/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:01:07 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/05 20:31:21 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <sstream>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	add_contact(const int	n_of_contacts);
	void	search_contact(const int	n_of_contacts);
private:
	Contact contact[8];
	int		oldest_entry;
};

#endif