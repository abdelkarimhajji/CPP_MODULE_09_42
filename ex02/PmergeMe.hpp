/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:17:55 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/10 15:42:27 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include <sstream>
#include <climits>

class   PmergeMe
{
    private:
        std::vector<int> args;
        int ac;
        void    checkErrors(char **av);
        void    cheackDuplicate();
        void    recursionFunction(int sizePair, int numberPairs);
        std::vector<int>    sortAll();
    public:
        PmergeMe();
        PmergeMe(int ac, char **av);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        static void error(std::string arg);
        void   sort();
        ~PmergeMe();
};

#endif