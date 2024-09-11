/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:07:16 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/11 14:50:10 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        BitcoinExchange bit(av[1]);
        bit.displayBitcoins();
    }
    else
    {
        std::cout << "error in arg\n" << std::endl;
        exit(1);
    }
    return 0;
}