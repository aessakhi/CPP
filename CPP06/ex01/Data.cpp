/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:22:08 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 18:45:22 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include "Data.hpp"

Data::Data(const std::string str): _name(str)
{
}

Data::~Data()
{
}

const std::string Data::getName() const
{
	return (this->_name);
}

void	Data::setName(const std::string name)
{
	this->_name = name;
}
