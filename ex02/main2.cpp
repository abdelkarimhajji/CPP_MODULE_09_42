/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:20:10 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/10 11:12:52 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>

void    sortAll(std::vector<int> &arr)
{
    std::vector<int> largeNumbers;
    std::vector<int> smallNumbers;
    // std::vector<int> arr2;
    for(int i = 0; i < arr.size(); i++)
    {
        if(i % 2 != 0)
            smallNumbers.push_back(arr[i]);
        else    
            largeNumbers.push_back(arr[i]);
    }
    
    // for(int i = 0; i < smallNumbers.size(); i++)
    //     std::cout << smallNumbers[i] << std::endl;
    int tmp;
    int valid = 0;
    int j = 0;
    for (int i = 0; i < largeNumbers.size(); i++)
    {
        if(i != j && largeNumbers[j] > largeNumbers[i])
        {
            tmp = largeNumbers[j];
            largeNumbers[j] = largeNumbers[i];
            largeNumbers[i] = tmp;
            valid = 1;
        }
        if(i + 1 == largeNumbers.size() && valid == 1)
        {
            valid = 0;
            j++;
            i = j;
        }   
    }
    //  for(int i = 0; i < largeNumbers.size(); i++)
    //     std::cout << largeNumbers[i] << std::endl;
    
    std::cout << "----------------\n";
   
    for(int i = 0; i < smallNumbers.size(); i++)
    {
        std::vector<int>::iterator lower = std::lower_bound(largeNumbers.begin(), largeNumbers.end(), smallNumbers[i]);
        if (lower == largeNumbers.end() || *lower != smallNumbers[i])
        {
            // If the target is larger than all numbers in the array, or it's not found in the array, insert it at the correct position
            largeNumbers.insert(lower, smallNumbers[i]);
        }
    }
     for(int i = 0; i < largeNumbers.size(); i++)
        std::cout << largeNumbers[i] << std::endl;
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
        // std::cout << "count: " << arr[count] << std::endl;
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
    // int jb[21] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101};
    // int st[19] = {3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575};
    int i = 0;
    // while (i < arr.size())
    // {
    //     std::cout << arr[i] << std::endl;
    //     i++;
    // }
    
    // std::cout << "-----------------------------------------\n";
    int counts = 0;
    // while (counts < rest.size())
    // {
    //     std::cout << "count: " << rest[counts] << std::endl;
    //     counts++;
    // }
    // std::cout << "-----------------------------------------\n";
    recursionFunction(arr, sizePair * 2, numberPairs / 2);
    if(!rest.empty())
    {
        for(int i = 0; i < rest.size();i++)
            arr.push_back(rest[i]);
    }
    // if(arrVector.size() >= 2 || !rest.empty())
    //     sortAll(arr, arrVector, rest);
    // std::cout << "-----------------------------------------\n";
}

int main()
{
    std::vector<int> arr;
    arr.push_back(58);
    arr.push_back(55);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(4);
    
    arr.push_back(16);
    arr.push_back(8);
    arr.push_back(74);
    
    arr.push_back(1);
    arr.push_back(110);
    arr.push_back(122);
    arr.push_back(18);
    arr.push_back(11);
    arr.push_back(18);
    

    recursionFunction(arr, 2, arr.size()/2);
    sortAll(arr);
    // for(int i = 0; i < arr.size(); i++)
    //     std::cout << arr[i] << std::endl;
    return 0;
}