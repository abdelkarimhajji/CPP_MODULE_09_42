/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:20:10 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/08 20:06:46 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>

void    recursionFunction(std::vector<int> &arr, int sizePair, int numberPairs)
{
    std::vector<int> rest;
    std::vector<std::vector<std::vector<int> > > arrVector;
    for (int i = 0; i < arr.size(); )
    {
        std::vector<std::vector<int> > pair;
        for (int k = 0; k < 2; k++)
        {
            std::vector<int> half;
            for (int j = 0; j < 4/2; j++)
                half.push_back(arr[i++]);
            pair.push_back(half);
        }
        arrVector.push_back(pair);
        std::cout << "hi ok \n";
    }
    std::cout << arrVector[0][1][0] << std::endl;
   for (int i = 0; i < numberPairs; i++)
    {
        if(arrVector[i].size() >= 2 && arrVector[i][0][0] > arrVector[i][1][0])
            std::swap(arrVector[i][0], arrVector[i][1]);
    }

    // for (int i = 0; i < 2;i++ )
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         for (int k = 0; k <4/2; k++)
    //             std::cout << arrVector[i][j][k] << std::endl;
            
    //     std::cout << "----------------\n";
    //     }
    // }
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
     arr.push_back(8);
    arr.push_back(55);
    arr.push_back(1);
    arr.push_back(110);
    arr.push_back(122);
    arr.push_back(18);
    
    
    recursionFunction(arr, 4, arr.size()/2);
    // for(int i = 0; i < arr.size(); i++)
    //     std::cout << arr[i] << std::endl;
    return 0;
}