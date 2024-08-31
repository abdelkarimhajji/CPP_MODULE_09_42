/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:35:48 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/31 14:04:14 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    error()
{
    std::cout << "Error" << std::endl;
    exit(0);
}

void returnIndex(char arg, char *operations, int *index, int size)
{
    
    for(int j = 0; j < size; j++)
    {
        if(arg == operations[j])
            *index = j;
    }
    if(*index == -1 && arg != ' ' && std::isdigit(arg) == false)
        error();
}

void    makeOperation(std::vector<int> &container, char *operations, int &count, int index)
{
        int  firstNumber = container[container.size() - 2];
        int secondNumber = container[container.size() - 1];
        int result;
        count--;
        switch(operations[index])
        {
            case '+':
                result = firstNumber + secondNumber;
                break;
            case '-':
                result = firstNumber - secondNumber;
                break;
            case '*':
                result = firstNumber * secondNumber;
                break;
            case '/':
                if(secondNumber != 0)
                    result = firstNumber / secondNumber;
                else
                    error();
                break;
            
        }
        container.pop_back();
        container.pop_back();
        container.push_back(result);
}
void    displayContainer(std::vector<int> &container)
{
    for (int i = 0; i < container.size(); i++)
        std::cout << container[i] << std::endl;
}

int main(int ac, char **av)
{
    int i = 0;
    int index = -1;
    int count  = 0;
    std::vector<int> container;
    char operations[] = {'+','-','*','/'};
    int size = sizeof(operations) / sizeof(operations[0]);
    while (av[1][i])
    {
        if(std::isdigit(av[1][i]) != false)
            container.push_back(av[1][i] - '0');
        else
        {
            returnIndex(av[1][i], operations, &index, size);
            if(index != -1)
            {
                count++;
                if(container.size() >= 2)
                    makeOperation(container, operations, count, index);
                index = -1;
            }
        }
       i++;
    }
    if(container.size() > 1 || count != 0)
        error();
    displayContainer(container); 
    return 0;
}