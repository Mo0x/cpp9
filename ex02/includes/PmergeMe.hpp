/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:57:44 by mgovinda          #+#    #+#             */
/*   Updated: 2025/03/17 16:48:27 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	private:
	std::vector<int> m_input;

	static void merge_insertion_sort_vec(std::vector<int> &vec);
	static void merge_insertion_sort_deque(std::deque<int> &dq);
	static std::vector<size_t> generate_jacob(size_t n);


	public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();
	
	PmergeMe(int ac, char **av);
	
	//member func
	void diplay_unsorted()const;
	void sort_and_displayer();
};

#endif
