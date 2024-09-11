/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:14:45 by ahajji            #+#    #+#             */
/*   Updated: 2024/09/11 19:22:54 by ahajji           ###   ########.fr       */
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
    size_t yearI;
    for(size_t i = 0; i < lenght; i++)
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
    size_t dayI;
    for(size_t i = lenght + 1; i < lenght + 3; i++)
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
    size_t monthI;
    for(size_t i = lenght - 2; i < lenght; i++)
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
        for(size_t i = pos + 1; i < line.length(); i++)
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

std::string  BitcoinExchange::returnValue(std::string line, size_t pos)
{
    std::string number;
    for(size_t i = pos + 1; i < line.length(); i++)
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
    return number;
}

std::pair<std::string, float>    BitcoinExchange::checkDateBitcF(std::string const& line)
{
    size_t pos = line.find('|');
    std::string number;
    float floatNumber = std::numeric_limits<float>::quiet_NaN();
    if(pos != std::string::npos)
    {
        number = returnValue(line, pos);
        std::stringstream str(number);
        str >> floatNumber;
        size_t pos2 = line.find(' ');
        if(pos2 != std::string::npos)
        {
            if(line[pos2 + 1] != '|')
                errorParse(1);
            return std::make_pair(line.substr(0, pos-1), floatNumber);
        }
        else
            errorParse(1);
    }
    else
    {
        size_t pos3 = line.find(' ');
        if(pos3 != std::string::npos)
            errorParse(1);
    }
    return std::make_pair(line.substr(0, line.length()), floatNumber);
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

int     BitcoinExchange::getYear(std::string date)
{
    size_t  pos = date.find('-');
    std::string yearStr = date.substr(0, pos);
    
    int year = std::atoi(yearStr.c_str());
    return year;
}

void    BitcoinExchange::checkErrors(std::string first, float second)
{
    std::map<std::string, float>::iterator it = this->database.lower_bound(first);
    if(isValidDate(first) == false)
        std::cout << "Error: bad input => " << first << std::endl;
    else if(std::isnan(second))
        std::cout << "Error: no value." << std::endl;
    else if(isValidDate(first) != false && (getYear(first) < 2009 || getYear(first) > 2024))
        std::cout << "Error: date not availabel" << std::endl;
    else if(second < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else if(second >= std::numeric_limits<int>::max() + 1.0f)
        std::cout << "Error: too large a number." << std::endl;
    else if (it != database.end())
        std::cout << std::setprecision(2) << first << " => " << second << " = " << second * it->second << std::endl;
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
                checkErrors(pair.first, pair.second);
            }     
            count++;
        }
    }
    else
        errorParse(0);
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    this->nameFile = other.nameFile;
    this->database = other.database;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other)
{
    if(this != &other)
    {
        this->nameFile = other.nameFile;
        this->database = other.database;
    }
    
    return *this;
}

void    BitcoinExchange::displayBitcoins()
{
    parseData();
    parseFile();
}