/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:38:24 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/08 17:04:16 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ifstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Incorrect number of args, try ./btc input.txt" << std::endl, exit(1);
	try
	{
		btc(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return (0);
}