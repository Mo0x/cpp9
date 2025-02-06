/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:38:24 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/06 17:40:03 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ifstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Incorrect number of args, try ./btc input.txt" << std::endl, exit(1);
	ifstream data("./data/data.cvs")
	if (data.fail())
		std::cerr << "Couldnt load data file." << std::endl, exit(1);
	ifstream input(av[1])
	if (data.fail())
		std::cerr << "Couldnt load input file." << std::endl, exit(1);
	btc(input, data);
	data.close();
	input.close();
	return (0);
}