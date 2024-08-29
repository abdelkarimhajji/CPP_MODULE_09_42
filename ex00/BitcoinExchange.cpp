/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:14:45 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/29 15:48:12 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(std::string const &file)
{
    this->nameFile = file;
}

BitcoinExchange::~BitcoinExchange()
{
   
}

void    BitcoinExchange::errorParse(int state)
{
    if(state == 0)
        std::cout << "error in arg" << std::endl;
    else if(state == 1)
        std::cout << "error in parse" << std::endl;
    std::exit(1);
}

void    BitcoinExchange::checkYear(size_t const& lenght, std::string line)
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

void    BitcoinExchange::checkDay(size_t const& lenght, std::string line)
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

void    BitcoinExchange::checkMonth(size_t const& lenght, std::string line)
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

void    BitcoinExchange::checkDate(std::string const& line)
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

void    BitcoinExchange::checkDateBitc(std::string const& line)
{
    size_t pos = line.find(',');
    std::string number;
    float floatNumber;
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
        str >> floatNumber;
        if(floatNumber > std::numeric_limits<int>::max())
            errorParse(1);
        checkDate(line);
        if(database.find(line.substr(0, pos)) == database.end())
            database[line.substr(0, pos)] = floatNumber;
        else
            errorParse(1);
    }
    else
        errorParse(0);
}

void    BitcoinExchange::parseData()
{
    std::ifstream file("data.csv");
    std::string line;
    int count = 0;
    if(file.is_open())
    {
        while (std::getline(file, line))
        {
            if(count == 0 && line != "date,exchange_rate")                  
                errorParse(1);
            else if(count != 0)
                checkDateBitc(line);
            count++;
        }
    }
    else
        errorParse(0);
}
void     BitcoinExchange::checkMonthF(size_t const& lenght, std::string line)
{
    
    std::string month;
    int monthI;
    for(int i = lenght - 2; i < lenght; i++)
        month += line[i];
    if(month[1] == '-' || month[0] == '+')
        errorParse(1);
    std::stringstream str(month);
    str >> monthI;
}
void    BitcoinExchange::checkYearF(size_t const& lenght, std::string line)
{
    std::string year;
    int yearI;
    for(int i = 0; i < lenght; i++)
    {
        if(std::isdigit(line[i]) == false)
            errorParse(1);
        year += line[i];
    }
    if(year[0] == '+')
        errorParse(1);
    std::stringstream str(year);
    str >> yearI;
}

void    BitcoinExchange::checkDateF(std::string const& line, int state)
{
    int count = 0;
    size_t pos = line.find('-');
    while (pos != std::string::npos)
    {
        if(count == 0)
            checkYearF(pos, line);
        if(count == 1)
        {
            checkMonthF(pos, line);
            checkDayF(pos, line, state);
        }
        pos = line.find('-', pos + 1);
        count++;
    }
    // if(count != 2)
    //     errorParse(1);
}

void    BitcoinExchange::checkDayF(size_t const& lenght, std::string line, int state)
{
    std::string day;
    int dayI;
    for(int i = lenght + 1; i < lenght + 3; i++)
        day += line[i];
    if(state == 1 && (day[0] == '+' || day[1] == ' ' || line.length() > 10))
        errorParse(1);
    else if(day[0] == '+' || day[1] == ' ')
        errorParse(1);
    std::stringstream str(day);
    str >> dayI;
}

std::pair<std::string, float>    BitcoinExchange::checkDateBitcF(std::string const& line)
{
    size_t pos = line.find('|');
    std::string number;
    float floatNumber = std::numeric_limits<float>::quiet_NaN();

    if(pos != std::string::npos)
    {
        for(int i = pos + 1; i < line.length(); i++)
        {
            if(((i == (pos + 1)) && line[i] != ' ') || line[pos+2] == '.')
                errorParse(1);
            else if (i != (pos + 1) && std::isdigit(line[i]) == false && line[i] != '.' && line[i] != '-')
                errorParse(1);
            else if(line[i + 1] == '\0' && std::isdigit(line[i]) == false)
                errorParse(1);
            if(i != (pos + 1))    
                number += line[i];
        }

        // std::cout << "this is first : " << "'"<<number <<"'"<< std::endl;
        std::stringstream str(number);
        str >> floatNumber;
        size_t pos2 = line.find(' ');
        if(pos2 != std::string::npos)
        {
            if(line[pos2 + 1] != '|')
                errorParse(1);
        }
        else
            errorParse(1);
        //     isValidDate(line.substr(0, ));
        //     // checkDateF(line, 0);
        // else
        //     errorParse(1);
        // isValidDate()
        
        // std::cout << "this is line ok for test : " << line << std::endl;
    }
    else
    {
         size_t pos3 = line.find(' ');
        if(pos3 != std::string::npos)
            errorParse(1);
        // checkDateF(line, 1);
        // std::cout << "this is line ok for test : " << line << std::endl;
    }
    //  std::cout << "this is first : " << floatNumber << std::endl;
    // std::cout << "before return : ok : '"<< line.substr(0, pos - 1)<< "'" << std::endl;
    return std::make_pair(line.substr(0, pos-1), floatNumber);
}

bool    BitcoinExchange::isValidDate(const std::string& date)
{
    std::stringstream ss(date);
    std::tm t = {};
    ss >> std::get_time(&t, "%Y-%m-%d");
    if (ss.fail()) {
        return false;
    }
    return true;
}

void    BitcoinExchange::parseFile()
{
    std::ifstream file(this->nameFile);
    std::pair<std::string, float> pair;
    std::string line;
    int count = 0;
    if(file.is_open())
    {
        while (std::getline(file, line))
        {
            if(count == 0 && line != "date | value")           
                errorParse(1);
            else if(count != 0)
            {
                pair = checkDateBitcF(line);
                // std::cout << "this is first : " << pair.first  << "=> " << pair.second << std::endl;
                std::map<std::string, float>::iterator it = this->database.lower_bound(pair.first);
                std::cout << "this is second " <<  pair.second <<std::endl;
                // if(pair.second < 0)
                //     std::cout << "Error: not a positive number." << std::endl;
                if(pair.second > std::numeric_limits<int>::max())
                    std::cout << "Error: too large a number." << std::endl;
                else if (it != database.end()) {
                    if(isValidDate(pair.first) != false)
                        std::cout << std::fixed << std::setprecision(2) << pair.first << " => " << pair.second << " = " << pair.second * it->second << std::endl;
                    else
                        std::cout << "Error: bad input => " << pair.first << std::endl;    
                }
                // else {
                //     std::cout << "Date not found, and no next greater date" << std::endl;
                // }
            }
                        
            count++;
        }
    }
    else
    {
        errorParse(0);
    }
}

void    BitcoinExchange::displayBitcoins()
{
    parseData();
    parseFile();
   std::map<std::string, float>::iterator it;
for (it = this->dataValue.begin(); it != this->dataValue.end(); ++it) {
    std::cout << std::fixed <<"Key: " << it->first << ", Value: " << it->second << "\n";
}
}
