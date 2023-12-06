/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:46:12 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/10 23:53:45 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	replace(const char *file, const std::string s1, const std::string s2);

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of args" << std::endl;
		return (0);
	}
	replace(argv[1], argv[2], argv[3]);
}