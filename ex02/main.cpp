/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:00:39 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/05 21:48:56 by ahajji           ###   ########.fr       */
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
// void merge(std::vector<int>& arr, int l, int m, int r) {
//     // Merge two subarrays arr[l..m] and arr[m+1..r] into a temporary array
//     std::vector<int> temp(r-l+1);
//     int i = l, j = m+1, k = 0;

//     while (i <= m && j <= r) {
//         if (arr[i] <= arr[j]) {
//             temp[k] = arr[i];
//             i++;
//         } else {
//             temp[k] = arr[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of the left and right subarrays, if any
//     while (i <= m) {
//         temp[k] = arr[i];
//         i++;
//         k++;
//     }
//     while (j <= r) {
//         temp[k] = arr[j];
//         j++;
//         k++;
//     }

//     // Copy the sorted subarray back to the original array
//     for (i = l; i <= r; i++) {
//         arr[i] = temp[i-l];
//     }
// }

// void mergeSort(std::vector<int>& arr, int l, int r) {
//     if (l < r) {
//         int m = l + (r - l) / 2; // Find the middle point

//         mergeSort(arr, l, m); // Sort first half
//         mergeSort(arr, m+1, r); // Sort second half

//         merge(arr, l, m, r); // Merge the sorted halves
//     }
// }