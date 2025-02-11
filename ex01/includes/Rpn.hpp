/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:54:42 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/11 14:36:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

class Rpn
{
	private:
	std::stack<int> m_stack;
	int add(int a, int b);
	int sub(int a, int b);
	int mult(int a, int b);
	int divide(int a, int b);
	int mod(int a, int b);

	public:
	Rpn();
	Rpn(const Rpn &src);
	Rpn &operator=(const Rpn &src);
	~Rpn();

	// member func
	void rpn(std::string input);
	void do_the_rpn_thing(std::string input);
};

void rpn(std::string input);
