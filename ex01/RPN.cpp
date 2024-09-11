/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:09:42 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/11 14:54:08 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    this->operations[0] = '+';
    this->operations[1] = '-';
    this->operations[2] = '*';
    this->operations[3] = '/';
    this->size = sizeof(operations) / sizeof(operations[0]);
}

RPN::~RPN()
{
    
}

RPN::RPN(RPN const &RPN)
{
    this->container = RPN.container;
    this->size = RPN.size;
    for(int i = 0; i < this->size; i++)
        this->operations[i] = RPN.operations[i];
}

RPN& RPN::operator=(RPN const &RPN)
{
    if(this != &RPN)
    {
        this->container = RPN.container;
        this->size = RPN.size;
        for(int i = 0; i < this->size; i++)
            this->operations[i] = RPN.operations[i];
    }
    return *this;
}

void    RPN::error()
{
    std::cout << "Error" << std::endl;
    exit(0);
}

void RPN::returnIndex(char arg, char *operations, int *index, int size)
{
    
    for(int j = 0; j < size; j++)
    {
        if(arg == operations[j])
            *index = j;
    }
    if(*index == -1 && arg != ' ' && std::isdigit(arg) == false)
        error();
}

void    RPN::displayContainer(std::vector<int> &container)
{
    for (size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << std::endl;
}

void    RPN::makeOperation(std::vector<int> &container, char *operations, int &count, int index)
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


void    RPN::calculate(char **av)
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
}