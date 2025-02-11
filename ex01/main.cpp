/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:25:36 by mgovinda          #+#    #+#             */
/*   Updated: 2025/02/11 14:46:09 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Too many args. Ex ./RPN \"3 4 +\"." << std::endl, 1);
	rpn(std::string(av[1]));
	return (0);
}
