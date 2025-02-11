/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:16 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/11 12:51:43 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

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
		m_rate = src.m_rate;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

static void trim(std::string &s)
{
	const std::string whitespace =" \t\n\r\f\v";
	size_t start = s.find_first_not_of(whitespace);
	if (start == std::string::npos)
		return;
	size_t end = s.find_last_not_of(whitespace);
	s = s.substr(start, end - start + 1);
}

// YYYY-MM-DD | 


static bool is_leap(int year)
{
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	return (year % 100 == 0);
}

static int get_days_int_month (int year, int month)
{
	switch (month)
	{
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return is_leap(year) ? 29 : 28;
		default:
			return 31;
	}
}

bool BitcoinExchange::is_valid_date(const std::string &date) const
{
	if (date.empty())
		return false;
	size_t	first_dash = date.find('-');
	if (first_dash == std::string::npos)
	{
		return false;
	}
	size_t	second_dash = date.find("-", first_dash + 1);
	if (second_dash == std::string::npos)
	{
		return false;
	}
	std::string year_str = date.substr(0, first_dash);
	std::string month_str = date.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day_str = date.substr(second_dash + 1);

	int year, month, day;
	std::istringstream ys(year_str), ms(month_str), ds(day_str);
	if (!(ys >> year) || !(ms >> month) || !(ds >> day))
	{
		return false;
	}
	if (month < 1 || month > 12)
		return false;
	int max_days = get_days_int_month(year, month);
	if (day < 1 || day > max_days)
		return false;
	return true;
}

bool BitcoinExchange::is_valid_value(const std::string &value) const
{
	if (value.empty())
	{
		return false;
	}
	if (value[0] == '-')
	{
		return false;
	}
	
	bool	has_dot = false;
	size_t	start = 0;

	if (value[0] == '+') start = 1;
	for (size_t i = start ; i < value.size(); ++i)
	{
		const char c = value[i];
		if (c == '.')
		{
			if (has_dot || i == start || i == value.size() -1)
			{
				return false;
			}
			has_dot = true;
		}
		else if (!isdigit(c))
			return false ;
	}

	std::istringstream vs(value);
	double  valuef;
	if (!(vs >> valuef) || valuef < 0 || valuef > 1000)
		return false;
	char garbage;
	if (vs >> garbage)
		return false;
	if (!has_dot)
	{
		if (valuef < 1)
			return false;
		if (valuef != static_cast<int>(valuef))
			return false;
	}
	return true;
}

void BitcoinExchange::load_data(const std::string &str_data)
{
	std::ifstream data(str_data.c_str());

	if (!data)
		throw std::runtime_error("Couldn't open file.");
	std::string line, date;
	double rate;
	if (std::getline(data, line))
	{
		if (line != "data,exchange_rate")
		{
			std::istringstream ss(line);
			if (std::getline(ss, date, ',') && (ss >> rate))
				m_rate[date] = rate;
		}
	}
	while (std::getline(data, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate))
			m_rate[date] = rate;
	}
}

void BitcoinExchange::load_intput(const std::string &str_input)
{
	std::ifstream input(str_input.c_str());;

	if (!input)
		throw std::runtime_error("Error: couldn't open file.");
	std::string input_line, date, amount;
	double value;
	bool first_line = true;

	while(std::getline(input, input_line))
	{
		if (input_line.empty())
		{
			std::cout << "Error: bad input => empty" << std::endl;
			continue;
		}
		if (first_line)
		{
			if (input_line == "date | value")
			{
				first_line = false;
				continue ;
			}
		}
		first_line = false;
		std::stringstream ss(input_line);
		if (input_line.length() < 13 || input_line[11] != '|' || input_line[10] != ' ' || input_line[12] != ' ')
		{
			input_line = input_line.empty() ? "empty" : input_line;
			std::cout << "Error: bad input => " << input_line << std::endl;
			continue ;
		}
		if (std::getline(ss, date, '|'))
		{
			trim(date);
			if (!std::getline(ss, amount))
			{
				std::cout << "Error: Bad input =>" << input_line << std::endl;
				continue ;
			}
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			trim(amount);
			//amount.erase(amount.find_first_not_of(" \n\r\t"));
			if (!is_valid_date(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue ;
			}
			if (!is_valid_value(amount))
			{
				std::cout << "Error: not a valid value." << std::endl;
				continue ;
			}
			try 
			{
				value = std::atof(amount.c_str());
			}
			catch (...)
			{
				std::cerr << "Error: invalid value format." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cout << "Error: too large number." << std::endl;
				continue ;
			}
			double rate = convert(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
		else
			std::cerr << "Error: bad input =>" << input_line << std::endl;
	}

}

double BitcoinExchange::convert(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = m_rate.lower_bound(date);
	if (it == m_rate.end() || it->first !=date)
	{
		if (it == m_rate.begin())
			return 0;
		--it;
	}
	return it->second;
}

void	btc(std::string input)
{
	BitcoinExchange btce;

	btce.load_data("./data/data.csv");
	btce.load_intput(input);
}
