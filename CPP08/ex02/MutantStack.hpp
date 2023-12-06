/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:42:22 by aessakhi          #+#    #+#             */
/*   Updated: 2022/07/31 22:48:39 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack(){};
	~MutantStack(){};
	MutantStack(MutantStack const &src): std::stack<T>(src){};
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator=(rhs);
		}
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(){return (std::stack<T>::c.begin());};
	const_iterator cbegin() const {return (std::stack<T>::c.begin());};
	iterator end(){return (std::stack<T>::c.end());};
	const_iterator cend() const {return (std::stack<T>::c.end());};

	reverse_iterator rbegin(){return (std::stack<T>::c.rbegin());};
	const_reverse_iterator crbegin() const {return (std::stack<T>::c.rbegin());};
	reverse_iterator rend(){return (std::stack<T>::c.rend());};
	const_reverse_iterator crend() const {return (std::stack<T>::c.rend());};
};

#endif