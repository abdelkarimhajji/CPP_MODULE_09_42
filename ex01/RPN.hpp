/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:38:45 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/31 15:48:29 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <vector>
#include <cctype>

class RPN
{
    private:
        std::vector<int> container;
        char operations[4];
        int size;
        void    error();
        void    returnIndex(char arg, char *operations, int *index, int size);
        void    displayContainer(std::vector<int> &container);
        void    makeOperation(std::vector<int> &container, char *operations, int &count, int index);
    public:
        RPN();
        RPN(RPN const &RPN);
        RPN& operator=(RPN const &RPN);
        void    calculate(char **av);
        ~RPN();
};

#endif