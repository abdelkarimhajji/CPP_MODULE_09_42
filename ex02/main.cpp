/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:00:39 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/05 13:19:05 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>

void    sortFunction(std::vector<int> arr, int half)
{
    
}

void     callfunction(std::vector<int> arr,  int i)
{
    if (i == arr.size()) {
        return;
    }
    std::cout << arr[i] << std::endl;
    callfunction(arr, i + 1);
    std::cout << arr[i] << std::endl;
    // int half = arr.size() / 2;
    // sortFunction(arr, half);
    // sortFunction(arr, half + 1);
}

int main()
{
    std::vector<int> arr;
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(14);
    arr.push_back(16);
    arr.push_back(18);
    arr.push_back(20);
    arr.push_back(22);
    arr.push_back(24);
    arr.push_back(26);
    
    callfunction(arr, 0);
    return 0;
}