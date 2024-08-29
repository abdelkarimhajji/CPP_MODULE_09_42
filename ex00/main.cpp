/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:07:16 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/29 10:11:01 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    errorParse(int state)
{
    if(state == 0)
        std::cout << "error in arg" << std::endl;
    else if(state == 1)
        std::cout << "error in parse" << std::endl;
    std::exit(1);
}

void    checkYear(size_t const& lenght, std::string line)
{
    std::string year;
    int yearI;
    for(int i = 0; i < lenght; i++)
        year += line[i];
    if(year[0] == '+')
        errorParse(1);
    std::stringstream str(year);
    str >> yearI;
    if(yearI > 2024 || yearI < 2009)
        errorParse(1);
}

void    checkMonth(size_t const& lenght, std::string line)
{
    
    std::string month;
    int monthI;
    for(int i = lenght - 2; i < lenght; i++)
        month += line[i];
    if(month[1] == '-' || month[0] == '+')
        errorParse(1);
    std::stringstream str(month);
    str >> monthI;
    if(monthI > 12 || monthI < 1)
        errorParse(1);
}


void    checkDay(size_t const& lenght, std::string line)
{
    std::string day;
    int dayI;
    for(int i = lenght + 1; i < lenght + 3; i++)
        day += line[i];
    if(day[0] == '+' || day[1] == ',')
        errorParse(1);
    std::stringstream str(day);
    str >> dayI;
    if(dayI > 31 || dayI < 1)
    {
       std::cout << dayI << std::endl; 
        errorParse(1);
    }
}


void    checkDate(std::string const& line)
{
    int count = 0;
    size_t pos = line.find('-');
    while (pos != std::string::npos)
    {
        if(count == 0)
            checkYear(pos, line);
        if(count == 1)
        {
            checkMonth(pos, line);
            checkDay(pos, line);
        }
        pos = line.find('-', pos + 1);
        count++;
    }
    if(count != 2)
        errorParse(1);
}


void    checkDateBitc(std::string const& line)
{
    size_t pos = line.find(',');
    std::string number;
    long intNumber;
    if(pos != std::string::npos)
    {
        for(int i = pos + 1; i < line.length(); i++)
        {
            if((i == (pos + 1)) && std::isdigit(line[i]) == false)
                errorParse(1);
            else if (i != (pos + 1) && std::isdigit(line[i]) == false && line[i] != '.')
                errorParse(1);
            else if(line[i + 1] == '\0' && std::isdigit(line[i]) == false)
                errorParse(1);
            number += line[i];
        }
        std::stringstream str(number);
        str >> intNumber;
        if(intNumber > std::numeric_limits<int>::max())
            errorParse(1);
        checkDate(line);
    }
    else
        errorParse(0);
}


int main()
{
    BitcoinExchange bit("fichier.txt");
    bit.displayBitcoins();
    // std::ifstream file("data.csv");
    // std::string line;
    // int count = 0;
    // if(file.is_open())
    // {
    //     while (std::getline(file, line))
    //     {
    //             if(count == 0 && line != "date,exchange_rate")                  
    //                 errorParse(1);
    //             else if(count != 0)
    //                 checkDateBitc(line);
    //         count++;
    //     }
    // }
    // else
    // {
    //     errorParse(0);
    // }
    return 0;
}