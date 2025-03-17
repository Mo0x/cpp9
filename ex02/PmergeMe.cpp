/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:57:40 by mgovinda          #+#    #+#             */
/*   Updated: 2025/03/17 16:48:19 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <deque>

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &src) :
	m_input(src.m_input)
{
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		m_input = src.m_input;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		try
		{
			int n = std::atoi(av[i]);
			if (n <= 0)
				throw std::invalid_argument("Only positive integers");
			m_input.push_back(n);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cerr << "Error: No valid number provided" << std::endl;
			std::exit(1);
		}
	}
	if (m_input.empty())
	{
		std::cerr << "Error: No valid numbers provided" << std::endl;
		std::exit(1);
	}
}

void PmergeMe::diplay_unsorted() const
{
	std::cout << "Before:";
	for (size_t i = 0; i < m_input.size(); i++)
	{
		std::cout << " " << m_input[i];
	}
	std::cout << std::endl;
}

void PmergeMe::sort_and_displayer()
{
	std::vector<int> vec = m_input;
	std::deque<int> dq(m_input.begin(), m_input.end());

	std::clock_t start_vec = std::clock();
	merge_insertion_sort_vec(vec);
	std::clock_t end_vec = std::clock();
	double time_vec = 1000000.0 *(end_vec - start_vec) / CLOCKS_PER_SEC;

	std::clock_t start_dq = std::clock();
	merge_insertion_sort_deque(dq);
	std::clock_t end_dq = std::clock();
	double time_dq = 10000000.0 * (end_dq - start_dq) / CLOCKS_PER_SEC;

	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout <<  " " << vec[i];
	std::cout << std::endl << std::endl;
	
	std::cout << "Time to process a range of " << m_input.size() << " elements with std::vector: " << time_vec << " µs" << std::endl;
	std::cout << "Time to process a range of " << m_input.size() << " elements with std::deque: " << time_dq << " µs" << std::endl;
}

void PmergeMe::merge_insertion_sort_vec(std::vector<int> &vec)
{
	if (vec.size() < 1)
		return ;
	std::vector<int> main, pending;
	size_t i;
	for (i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		main.push_back(vec[i +1]);
		pending.push_back(vec[i]);
	}
	if (i < vec.size())
		pending.push_back(vec[i]);
	merge_insertion_sort_vec(main);
	std::vector<size_t> order = generate_jacob(pending.size());
	for (size_t j = 0; j < order.size(); j++)
	{
		size_t idx = order[j];
		if (idx < pending.size())
		{	
			int element = pending[idx];
			std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), element);
			main.insert(it, element);
		}
	}
	vec = main;
}

void PmergeMe::merge_insertion_sort_deque(std::deque<int> &dq)
{
	if(dq.size()<= 1)
		return;
	std::deque<int> main, pending;
	size_t i;
	for (i = 0; i + 1 < dq.size(); i += 2)
	{
		if (dq[i] > dq[i + 1])
			std::swap(dq[i], dq[i + 1]);
		main.push_back(dq[i]);
		pending.push_back(dq[i + 1]);
	}
	if (i < dq.size())
		pending.push_back(dq[i]);
	
	merge_insertion_sort_deque(main);
	std::vector<size_t> order = generate_jacob(pending.size());
	for (size_t j = 0; j < order.size(); ++j)
	{
		size_t idx = order[j];
		if (idx < pending.size())
		{
			int element = pending[idx];
			std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(),element);
			main.insert(it, element);
		}
	}
	dq = main;
}

std::vector <size_t> PmergeMe::generate_jacob(size_t n)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob(2, 0);
	jacob[1] = 1;
	while(jacob.back() <= n)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() -2]);
	for (size_t i = 2; i < jacob.size(); ++i)
	{
		size_t end = jacob[i];
		size_t start = jacob[i -1] + 1;
		if (start > n)
			break;
		end = std::min(end, n);
		for (size_t j = end; j >= start; --j)
			order.push_back(j - 1);
	}
	if (order.empty() || order[0] != 0)
		order.insert(order.begin(), 0);
	return order;
}
