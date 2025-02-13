/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:32 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/13 14:27:29 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **argv)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << argv[0] << " *sequence of positive intergers* " << std::endl;
		return 1;
	}
	try 
	{
		PmergeMe sorter(ac, av);
		sorter.diplay_unsorted();
		sorter.sort_and_display();
	}
	catch
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}