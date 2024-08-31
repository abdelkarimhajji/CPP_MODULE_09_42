/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:35:48 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/31 12:25:46 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    error()
{
    std::cout << "Error" << std::endl;
    exit(0);
}

int main(int ac, char **av)
{
    int i = 0;
    int index = -1;
    std::vector<int> container;
    char operations[] = {'+','-','*','/'};
    int size = sizeof(operations) / sizeof(operations[0]);
    while (av[1][i])
    {
        // std::cout << "'" << av[1][i] << "'" ;
        if(std::isdigit(av[1][i]) != false)
            container.push_back(av[1][i] - '0');
        else
        {
            for(int j = 0; j < size; j++)
            {
                if(av[1][i] == operations[j])
                    index = j;
            }
            // if(index != -1)
            //     std::cout << "operation[j] : " << operations[index] << std::endl;
       
        if(index == -1 && av[1][i] != ' ' && std::isdigit(av[1][i]) == false)
            error();
        else if(index != -1)
        {
            // std::cout <<"size  '" << container.size() << "'"<<std::endl;
            if(container.size() >= 2)
            {
                // std::cout <<"result '" << operations[index] << "'"<<std::endl;
                int  firstNumber = container[container.size() - 2];
                int secondNumber = container[container.size() - 1];
                // std::cout << "first number : " <<firstNumber << std::endl;
                // std::cout << "second number : " <<secondNumber << std::endl;
                int result;
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
            index = -1;
        }
        }
    
       i++;
    }
    i = 0;
    //  std::cout << container[container.size() - 2] << std::endl;
    while (i < container.size())
    {
        std::cout << container[i] << std::endl;
        i++;
    }
    
    return 0;
}