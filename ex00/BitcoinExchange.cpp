/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:41:16 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/08 18:49:17 by mgovinda         ###   ########.fr       */
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

static void trim(std::string &s)
{
	const std::string whitespace =" \t\n\r\f\v";
	size_t start = s.find_first_not_of(whitespace);
	if (start == std::string::npos)
		return "";
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

bool BitcoinExchange::is_valid_data(const std::string &date, Date &extracted) const
{
	while (std::isspace(date))
		date++;
	if (date)
	size_t	first_dash = date.find('-');
	if (first_dash == std::string::npos)
		return false;
	size_t	sedond_dash = date.find("-", first_dash + 1);
	if (second_dash == std::string::npos)
		return false;
	std::string year_str = date.substr(0, first_dash);
	std::string month_str = date.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day_str = datte.substr(secondash + 1);

	int year, month, date;
	std::istringstream ys(year_str), ms(month_str), ds(day_str);
	if (!(ys >> year) || !(ms >> month) || !(ds >> day))
		return false;
	if (month < 1 || month > 12)
		return false;
	
	int max_days = get_days_int_month(year, month);
	if (day < 1 || day > max_days)
		return false;
	extracted.year = year;
	extracted.month = month;
	extracted.day = day;
	return true;
}

bool BitcoinExchange::is_valid_value(const std::string &value) const
{
	if (value.empty())
		return false;
	if (value[0] == '-')
		return false;
	
	bool	has_dot = false;
	size_t	start = 0;

	if (value[0] == '+') start = 1;
	for (size_t i = start ; i < value.size(); ++i)
	{
		const char c = value[i];
		if (c == '.')
		{
			if (has_dot || i == start || i == value.size() -1)
				return false;
			has_dot = true;
		}
		else if (!isdigit(c))
			return false
	}

	std::isstringstream vs(value);
	double  valuef;
	if (!(vs >> valuef) || num < 0 || num > 1000)
		return false;
	char garbage;
	if (vs >> garbage)
		return false;
	if (!has_dot)
	{
		if (num < 1)
			return false;
		if (num != static_cast<int>(num))
			return false;
	}
	return true;
}

void BitcoinExchange::load_data(std::string str_data)
{
	std::ifstream data(str_data.c_str());
	if (data.fail())
		throw std::runtime_error("Couldn't open file.");
	std::string line, data;
	double rate;
	if (std::getline(file, line))
	{
		if (line != "data,exchange_rate")
		{
			std::istringstream ss(line);
			if (std::getline(ss, date, ",") && (ss >> rate))
				m_rate[date] = rate;
		}
	}
	while (std::getline(file, line))
	{
		std::stringstrean ss(line);
		if (getline(ss,date, "," && (ss >> rate)))
			m_rate[date] = rate;
	}
}

void BitcoinExchange::load_intput(const std::string &str_input)
{
	std::ifstream input(str_input.c_str());;

	if (input.fail())
		throw std::runtime_error("Error: couldn't open file.");
	std::string input_line, date, amount;
	double value;
	bool first_line = true;

	while(std::getline(file, input_line))
	{
		trim(input_line);
		if (first_line)
		{
			if (input_line == "date | vlue")
			{
				first_line = false;
				continue ;
			}
		}
		first_line = false;
		std::stringstream ss(input_line);
		if (intput_line[11] != '|' || input_line[10] != ' ' || input_line[12] != ' ')
		{

		}
	}

}

void	btc(std::string input)
{
	BitcoinExchange btce;

	btce.load_data("./data/data.csv");
	btce.load_intput(input);
}