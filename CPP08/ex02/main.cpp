#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "MAIN DU SUJET" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Last element: ";
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: ";
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << "Size after push: ";
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "CHECK COPY CONSTRUCTOR" << std::endl;
	MutantStack<int> cpy(mstack);
	MutantStack<int>::iterator it_cpy = cpy.begin();
	MutantStack<int>::iterator ite_cpy = cpy.end();
	++it_cpy;
	--it_cpy;
	while (it_cpy != ite_cpy)
	{
		std::cout << *it_cpy << std::endl;
		++it_cpy;
	}
	std::cout << std::endl;
	
	std::cout << "CHECK ASSIGNMENT OPERATOR" << std::endl;
	MutantStack<int> assign;
	assign = mstack;
	MutantStack<int>::iterator it_assign = assign.begin();
	MutantStack<int>::iterator ite_assign = assign.end();
	++it_assign;
	--it_assign;
	while (it_assign != ite_assign)
	{
		std::cout << *it_assign << std::endl;
		++it_assign;
	}
	std::cout << std::endl;

	std::cout << "Iterator (non const)" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		*it = *it + 1;
		++it;
	}
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "Iterator (const)" << std::endl;
	MutantStack<int>::const_iterator cit = mstack.cbegin();
	MutantStack<int>::const_iterator cite = mstack.cend();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << std::endl;

	std::cout << "Reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		*rit = *rit + 1;
		++rit;
	}
	rit = mstack.rbegin();
	rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << std::endl;

	std::cout << "Reverse iterator (const)" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.crend();
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}
	std::cout << std::endl;
}

/* !! WITH LISTS!!
int main()
{
std::list<int> mstack;
mstack.push_back(5);
mstack.push_back(17);
std::cout << mstack.back() << std::endl;
mstack.pop_back();
std::cout << mstack.size() << std::endl;
mstack.push_back(3);
mstack.push_back(5);
mstack.push_back(737);
//[...]
mstack.push_back(0);
std::list<int>::iterator it = mstack.begin();
std::list<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::list<int> s(mstack);
return 0;
}
 */
