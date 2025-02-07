/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:16 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/07 16:24:45 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <ifstream>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) :
	m_rate(src.m_rate)
{
	return ;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		m_rate = src.m_rate();
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

// YYYY-MM-DD | 

bool BitcoinExhange::is_valid_data(const std::string &date) const
{
	while (std::isspace(date))
		date++;
	if (date)
}