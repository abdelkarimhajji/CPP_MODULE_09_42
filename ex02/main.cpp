/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:17:55 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/10 13:22:33 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    error(std::string arg)
{
    std::cout << arg << std::endl;
    exit(0);
}

std::vector<int>    sortAll(std::vector<int> &arr)
{
    std::vector<int> largeNumbers;
    std::vector<int> smallNumbers;
    for(int i = 0; i < arr.size(); i++)
    {
        if(i % 2 != 0)
            smallNumbers.push_back(arr[i]);
        else    
            largeNumbers.push_back(arr[i]);
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

void    recursionFunction(std::vector<int> &arr, int sizePair, int numberPairs)
{
    std::vector<int> rest;
    std::vector<std::vector<std::vector<int> > > arrVector;
    
    if(numberPairs < 1)
        return;
    int count = numberPairs * sizePair;
    while (count < arr.size())
    {
        rest.push_back(arr[count]);
        count++;
    }
    
    for (int i = 0; i < numberPairs * sizePair; )
    {
        std::vector<std::vector<int> > pair;
        for (int k = 0; k < 2; k++)
        {
            std::vector<int> half;
            for (int j = 0; j < sizePair/2; j++)
                half.push_back(arr[i++]);
            pair.push_back(half);
        }
        arrVector.push_back(pair);
    }

    for (int i = 0; i < numberPairs; i++)
    {
        if(arrVector[i][0].back() > arrVector[i][1].back())
            std::swap(arrVector[i][0], arrVector[i][1]);
    }
    arr.clear();
    for (int i = 0; i < numberPairs;i++ )
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k <sizePair/2; k++)
            {
                
                arr.push_back(arrVector[i][j][k]);
            }
            
        }
    }
    
    recursionFunction(arr, sizePair * 2, numberPairs / 2);
    if(!rest.empty())
    {
        for(int i = 0; i < rest.size();i++)
            arr.push_back(rest[i]);
    }
}

int main(int ac, char **av)
{
    std::vector<int> arr;
    std::vector<int> sortumbers;
    
    if(ac < 2)
        error("Not enough args");
    
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
        arr.push_back(std::atoi(av[i]));
    }
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i + 1; j < arr.size(); j++)
        {
            if(arr[i] == arr[j])
                error("Duplicate Number");
        }
    }
    recursionFunction(arr, 2, arr.size()/2);
    sortumbers = sortAll(arr);
    for(int i = 0; i < sortumbers.size(); i++)
        std::cout << sortumbers[i] << std::endl;
    return 0;
}