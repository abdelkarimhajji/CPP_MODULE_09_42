/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:17:55 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/11 08:22:08 by ahajji           ###   ########.fr       */
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
#include <ctime>
#include <deque>

class   PmergeMe
{
    private:
        std::vector<int> args;
        std::deque<int> args_;
        int ac;
        void    checkErrors(char **av);
        void    cheackDuplicate();
        void    recursionFunction(int sizePair, int numberPairs);
        void    recursionFunction_(int sizePair, int numberPairs);
        std::vector<int>    sortAll();
        std::deque<int>    sortAll_();
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