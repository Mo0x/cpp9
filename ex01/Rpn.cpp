/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:32:54 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/11 14:49:08 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <sstream>
#include "Rpn.hpp"

Rpn::Rpn()
{
	return ;
}

Rpn::Rpn(const Rpn &src) :
	m_stack(src.m_stack)
{
	return ;
}

Rpn &Rpn::operator=(const Rpn &src)
{
	if (this != &src)
		m_stack = src.m_stack;
	return (*this);
}

Rpn::~Rpn()
{
	return ;
}

int Rpn::add(int a, int b)
{
	return (a + b);
}

int Rpn::sub(int a, int b)
{
	return (a - b);
}

int Rpn::mult(int a, int b)
{
	return (a * b);
}

int Rpn::divide(int a, int b)
{
	return (b != 0 ? a / b : throw std::runtime_error("Division by zero!"));
}

int Rpn::mod(int a, int b)
{
	return (b != 0 ? a % b : throw std::runtime_error("Modulo by zero!"));
}


void Rpn::do_the_rpn_thing(std::string input)
{
	std::istringstream ss(input);
	std::string token;

	while (ss >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
			m_stack.push(token[0] - '0');
		else if (token == "*" || token == "+" || token == "-" || token == "/" || token == "%")
		{
			if (m_stack.size() < 2)
			{
				std::cerr << "Error: not enough operands.\n";
				return ;
			}
			int a = m_stack.top();
			m_stack.pop();
			int b = m_stack.top();
			m_stack.pop();
			int (Rpn::*operation)(int, int) = NULL;
			if (token == "+") 
				operation = &Rpn::add;
			else if (token == "-" )
				operation = &Rpn::sub;
			else if (token == "*" )
				operation = &Rpn::mult;
			else if (token == "/" )
				operation = &Rpn::divide;
			else if (token == "%" )
				operation = &Rpn::mod;
			if (operation)
			{
				int ret = (this->*operation)(b, a);
				m_stack.push(ret);
			}

			//here to a pointer to member func to choose operation to do with a and b
		}
		else
		{
			std::cerr << "Error invalid input." << std::endl;
			return ;
		}
	}
	if (m_stack.size() == 1)
	{
		std::cout << "Result: " << m_stack.top() << std::endl;
		return ;
	}
	else
	{
		std::cerr << "Error: Too many operands." << std::endl;
		return ;
	}
}

void rpn(std::string input)
{
	Rpn rpn_instance;
	try
	{
		rpn_instance.do_the_rpn_thing(input);
	}
	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

