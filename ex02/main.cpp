/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:00:39 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/08 09:43:45 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<vector>

// void    sortFunction(std::vector<int> arr, int half)
// {
    
// }

// void     callfunction(std::vector<int> arr,  int l, int r)
// {
//     // if (l < r) {
//     //     int m = l + (r - l) / 2;
//     //     std::cout << "left : " << arr[l] << std::endl;
//     //     std::cout << "right : " << arr[r] << std::endl;
//     //     callfunction(arr, l, m);
//     //    std::cout << "2left : " << arr[l] << std::endl;
//     //     std::cout << "2right : " << arr[r] << std::endl;
//     // // int half = arr.size() / 2;
//     // // sortFunction(arr, half);
//     // // sortFunction(arr, half + 1);
//     // }
//     if(arr.size() == r)
//         return;
//     std::cout << "this is after r => " << arr[r] << std::endl;
//     callfunction(arr, 0, r + 1);
//     if(r <= 2)
//         return;
//     callfunction(arr, 0, r - 1);
//     std::cout << "this is befor r => " << arr[r] << std::endl;
// }

// int main()
// {
//     std::vector<int> arr;
//     arr.push_back(4);
//     arr.push_back(8);
//     arr.push_back(10);
//     arr.push_back(12);
//     arr.push_back(14);
//     arr.push_back(16);
//     arr.push_back(18);
//     arr.push_back(20);
//     arr.push_back(22);
//     arr.push_back(24);
//     arr.push_back(26);
    
//     // callfunction(arr, 0, arr.size() - 1);
//     callfunction(arr, 0, 0);
//     return 0;
// }

#include <iostream>
using namespace std;

void merge(int* arr, int* arrL, int* arrR, int sizeL, int sizeR) {
    int l = 0, r = 0, i = 0;
    while (l < sizeL && r < sizeR) {
        if (arrL[l] < arrR[r]) {
            arr[i++] = arrL[l++];
        } else {
            arr[i++] = arrR[r++];
        }
    }
    while (l < sizeL) {
        arr[i++] = arrL[l++];
    }
    while (r < sizeR) {
        arr[i++] = arrR[r++];
    }
}

void mergeSort(int* arr, int size) {
    if (size < 2) return;

    int mid = size / 2;
    int* arrL = new int[mid];
    int* arrR = new int[size - mid];

    for (int i = 0; i < mid; i++) {
        arrL[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        arrR[i - mid] = arr[i];
    }

    mergeSort(arrL, mid);
    mergeSort(arrR, size - mid);

    merge(arr, arrL, arrR, mid, size - mid);

    delete[] arrL;
    delete[] arrR;
}

int main() {
    int arr[] = {8, 5, 4, 3, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, size);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}