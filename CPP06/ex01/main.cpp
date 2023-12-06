/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:02:36 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/30 16:53:48 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main()
{
	uintptr_t ptr;

	Data data("Random name");

	ptr = serialize(&data);
	Data *data2 = deserialize(ptr);
	std::cout << &data << std::endl;
	std::cout << data2 << std::endl;

	std::cout << "If it works, should also change for data2" << std::endl;
	data.setName("OK");
	std::cout << data2->getName() << std::endl;
}
