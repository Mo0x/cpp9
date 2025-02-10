/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:04:32 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/10 18:36:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <istream>
#include <map>

class BitcoinExchange
{
	private:
	std::map<std::string, double> m_rate;
	bool is_valid_date(const std::string &date) const;
	bool is_valid_value(const std::string &value) const;

	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();
	
	//member func
	void load_data(const std::string &data);
	void load_intput(const std::string &input);
	double	convert(const std::string &date) const;

};

void btc(std::string input);

#endif
