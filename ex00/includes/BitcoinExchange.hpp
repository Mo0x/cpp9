/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:04:32 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/07 17:14:30 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ifstream>
#include <map>

struct Date
{
	int	year;
	int	month;
	int	day;
};


class BitcoinExchange
{
	private:
	std::map<std::string, double> m_rate;
	bool is_valid_data(const std::string &date) const;
	bool is_valid_value(const std::string &value) const;

	public:
	BitcoinExchange()
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();
	
	//member func
	void load_data(std::string data);
	void load_intput(std::string input);
	double	convert(std::string &date, std::string amount) const;

}

#endif
