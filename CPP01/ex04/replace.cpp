/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:46:25 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/23 13:01:24 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int		open_files(const char *file, std::ifstream *input, std::ofstream *output)
{
	std::string	filename;

	(*input).open(file);
	if ((*input).fail())
	{
		std::cerr << file << " not found" << std::endl;
		return (0);
	}
	filename = std::string(file) + std::string(".replace");
	(*output).open(filename.c_str());
	if ((*output).fail())
	{
		std::cerr << "Error creating " << filename << std::endl;
		(*input).close();
		return (0);
	}
	return (1);
}

void	find_and_replace(std::string &line, const std::string s1, const std::string s2)
{
	std::string::size_type	pos;

	if (s1.compare("") == 0 && s2.compare("") == 0)
		return ;
	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		if (s1.compare("") != 0)
			line.erase(pos, s1.length());
		if (s1.compare("") != 0 && s2.compare("") != 0)
			line.insert(pos, s2);
		pos = pos + s2.length();
		pos = line.find(s1, pos);
	}
}

void	replace(const char *file, const std::string s1, const std::string s2)
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		line;

	if (!open_files(file, &input, &output))
		return ;
	while (getline(input, line))
	{
		find_and_replace(line, s1, s2);
		output << line;
		if (!input.eof())
			output << std::endl;
	}
}
