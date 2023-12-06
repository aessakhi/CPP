/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:56:22 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/28 01:00:15 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): Form("Shrubbery creation form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): Form("Shrubbery creation form", 145, 137), _target(src._target)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return (*this);
}

void	ShrubberyCreationForm::execForm() const
{
	std::string	filename;
	std::ofstream	output;
	std::string	ascii;

	filename = this->_target + "_shrubbery";
	output.open(filename.c_str());
	if (output.fail())
	{
		std::cerr << "Couldn't create file " << filename << std::endl;
		return ;
	}
	ascii = "          &&& &&  & && \n \
      && &\\/&\\|& ()|/ @, && \n \
      &\\/(/&/&||/& /_/)_&/_& \n \
   &() &\\/&|()|/&\\/ '%\" & () \n \
  &_\\_&&_\\ |& |&&/&__%_/_& && \n \
&&   && & &| &| /& & % ()& /&& \n \
 ()&_---()&\\&\\|&&-&&--%---()~ \n \
     &&     \\||| \n \
             ||| \n \
             ||| \n \
             ||| \n \
       , -=-~  .-^- _ \n \
              ` \n";
	output << ascii;
	output.close();
	return ;
}