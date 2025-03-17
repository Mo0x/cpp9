/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:24:32 by mgovinda          #+#    #+#             */
/*   Updated: 2025/03/17 16:49:27 by mgovinda         ###   ########.fr       */
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
		PmergeMe sorter(ac, argv);
		sorter.diplay_unsorted();
		sorter.sort_and_displayer();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
