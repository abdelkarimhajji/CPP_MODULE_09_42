/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:20:55 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/10 15:43:48 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}


void    PmergeMe::error(std::string arg)
{
    std::cout << arg << std::endl;
    exit(0);
}

void    PmergeMe::cheackDuplicate()
{
    for(int i = 0; i < args.size(); i++)
    {
        for(int j = i + 1; j < args.size(); j++)
        {
            if(args[i] == args[j])
                error("Duplicate Number");
        }
    }
}

void    PmergeMe::checkErrors(char **av)
{
    for(int i = 1; i < ac; i++)
    {
        long long num;
        std::istringstream(av[i]) >> num;
        if(num > INT_MAX)
            error("Number Large than max int");
        if(num < 0)
            error("Negative Number");
        for(int j = 0; j < av[i][j]; j++)
        {
            if(!std::isdigit(av[i][j]))
                error("Is not digit");
        }
        args.push_back(std::atoi(av[i]));
    }
}

PmergeMe::PmergeMe(int ac, char **av) : ac(ac)
{
    checkErrors(av);
    cheackDuplicate();
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    // if(*this != other)
    
}



PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    return *this;
}

PmergeMe::~PmergeMe()
{
    
}
void    PmergeMe::recursionFunction(int sizePair, int numberPairs)
{
    std::vector<int> rest;
    std::vector<std::vector<std::vector<int> > > arrVector;
    
    if(numberPairs < 1)
        return;
    int count = numberPairs * sizePair;
    while (count < args.size())
    {
        rest.push_back(args[count]);
        count++;
    }
    
    for (int i = 0; i < numberPairs * sizePair; )
    {
        std::vector<std::vector<int> > pair;
        for (int k = 0; k < 2; k++)
        {
            std::vector<int> half;
            for (int j = 0; j < sizePair/2; j++)
                half.push_back(args[i++]);
            pair.push_back(half);
        }
        arrVector.push_back(pair);
    }

    for (int i = 0; i < numberPairs; i++)
    {
        if(arrVector[i][0].back() > arrVector[i][1].back())
            std::swap(arrVector[i][0], arrVector[i][1]);
    }
    args.clear();
    for (int i = 0; i < numberPairs;i++ )
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k <sizePair/2; k++)
            {
                
                args.push_back(arrVector[i][j][k]);
            }
            
        }
    }
    
    recursionFunction(sizePair * 2, numberPairs / 2);
    if(!rest.empty())
    {
        for(int i = 0; i < rest.size();i++)
            args.push_back(rest[i]);
    }
}

std::vector<int>    PmergeMe::sortAll()
{
    std::vector<int> largeNumbers;
    std::vector<int> smallNumbers;
    for(int i = 0; i < args.size(); i++)
    {
        if(i % 2 != 0)
            smallNumbers.push_back(args[i]);
        else    
            largeNumbers.push_back(args[i]);
    }
    int tmp;
    int valid = 0;
    int j = 0;
    for (int j = 0; j < largeNumbers.size(); j++) {
        for (int i = j + 1; i < largeNumbers.size(); i++) {
            if (largeNumbers[j] > largeNumbers[i]) {
                int tmp = largeNumbers[j];
                largeNumbers[j] = largeNumbers[i];
                largeNumbers[i] = tmp;
            }
        }
    }
   
    for(int i = 0; i < smallNumbers.size(); i++)
    {
        std::vector<int>::iterator lower = std::lower_bound(largeNumbers.begin(), largeNumbers.end(), smallNumbers[i]);
        largeNumbers.insert(lower, smallNumbers[i]);
    }
    return (largeNumbers);
}
void    PmergeMe::sort()
{
    recursionFunction(2, args.size()/2);
    args = sortAll();
    for(int i = 0; i < args.size(); i++)
        std::cout << args[i] << std::endl;
}