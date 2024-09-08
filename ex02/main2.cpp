/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:20:10 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/08 16:05:42 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>

void    recursionFunction(std::vector<int> &arr, int sizePair, int numberPairs)
{
    std::vector<int> rest;
    std::vector<std::vector<std::vector<int>> > arrVector;
    for (int i = 0; i < arr.size(); )
    {
        std::vector<std::vector<int>> pair;
        std::vector<int> half;
        for (int j = 0; j < 2/2; j++)
            half.push_back(arr[i++]);
        pair.push_back(half);
        arrVector.push_back(pair);
        std::cout << "hi ok \n";
    }

    // for (int i = 0; i < numberPairs - 1; i++)
    // {
    //     if(arrVector[i][1] < arrVector[i + 1][1])
    //         std::swap(arrVector[i], arrVector[i + 1]);
    // }

    for (int i = 0; i < numberPairs;i++ )
    {
        for (int j = 0; j < 2; j++)
            std::cout << arrVector[i][j] << std::endl;
        std::cout << "----------------\n";
    }
}

int main()
{
    std::vector<int> arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(12);
    arr.push_back(10);
    arr.push_back(16);
    arr.push_back(14);
    
    
    recursionFunction(arr, 2, arr.size()/2);
    // for(int i = 0; i < arr.size(); i++)
    //     std::cout << arr[i] << std::endl;
    return 0;
}