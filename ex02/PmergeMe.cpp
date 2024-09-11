/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:20:55 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/11 08:24:34 by ahajji           ###   ########.fr       */
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
        args_.push_back(std::atoi(av[i]));
    }
}

PmergeMe::PmergeMe(int ac, char **av) : ac(ac)
{
    checkErrors(av);
    cheackDuplicate();
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->args = other.args;
    this->args_ = other.args_;
    this->ac = other.ac;
}



PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        this->args = other.args;
        this->args_ = other.args_;
        this->ac = other.ac;
    }
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

void    PmergeMe::recursionFunction_(int sizePair, int numberPairs)
{
    std::deque<int> rest;
    std::deque<std::deque<std::deque<int> > > arrList;
    
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
        std::deque<std::deque<int> > pair;
        for (int k = 0; k < 2; k++)
        {
            std::deque<int> half;
            for (int j = 0; j < sizePair/2; j++)
                half.push_back(args[i++]);
            pair.push_back(half);
        }
        arrList.push_back(pair);
    }

    for (int i = 0; i < numberPairs; i++)
    {
        if(arrList[i][0].back() > arrList[i][1].back())
            std::swap(arrList[i][0], arrList[i][1]);
    }
    args_.clear();
    for (int i = 0; i < numberPairs;i++ )
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k <sizePair/2; k++)
            {
                
                args_.push_back(arrList[i][j][k]);
            }
            
        }
    }
    recursionFunction(sizePair * 2, numberPairs / 2);
    if(!rest.empty())
    {
        for(int i = 0; i < rest.size();i++)
            args_.push_back(rest[i]);
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
                std::swap(largeNumbers[j],largeNumbers[i]);
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

std::deque<int>    PmergeMe::sortAll_()
{
    std::deque<int> largeNumbers;
    std::deque<int> smallNumbers;
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
                std::swap(largeNumbers[j],largeNumbers[i]);
            }
        }
    }
    for(int i = 0; i < smallNumbers.size(); i++)
    {
        std::deque<int>::iterator lower = std::lower_bound(largeNumbers.begin(), largeNumbers.end(), smallNumbers[i]);
        largeNumbers.insert(lower, smallNumbers[i]);
    }
    return (largeNumbers);
}

void    PmergeMe::sort()
{
    if(ac < 2)
        error("You should be Pass to constructer numbers and number of numbers");
    std::vector<int> before = this->args;
    std::clock_t start = std::clock();
    recursionFunction(2, args.size()/2);
    args = sortAll();
    std::clock_t end = std::clock();
    double diff = 1000.0 * (end-start) / CLOCKS_PER_SEC;
    std::cout << "Before: ";
    for(int i = 0; i < 5; i++)
        std::cout  << before[i] << " ";
    if(args.size() > 5)
        std::cout << " [...]";
    std::cout << "\n";
    std::cout << "After: ";
    for(int i = 0; i < 5; i++)
        std::cout << args[i] << " ";
    if(args.size() > 5)
        std::cout << " [...]";
    std::cout << "\n";
    std::cout << "Time to process a range of " << args.size() << " elements with std::vector : " << diff << " us\n";
    std::clock_t start2 = std::clock();
    std::deque<int> before_ = this->args_;
    recursionFunction_(2, args_.size()/2);
    args_ = sortAll_();
    std::clock_t end2 = std::clock();
    double diff2 = 1000.0 * (end-start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << args_.size() << " elements with std::list : " << diff2 << " us\n";
}






















