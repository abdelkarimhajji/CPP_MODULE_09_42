/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:17:55 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/10 19:38:07 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
        PmergeMe::error("Not enough args");
    PmergeMe k(ac, av);
    k.sort();
    return 0;
}