/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:00:56 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/30 11:12:02 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <map>
#include <cmath>
#include <utility>

class BitcoinExchange
{
    private:
        std::string nameFile;
        std::map<std::string, float> database;
        void    errorParse(int state);
        void    checkDateBitc(std::string const& line);
        void    checkDate(std::string const& line);
        void    checkDay(size_t const& lenght, std::string line);
        void    checkMonth(size_t const& lenght, std::string line);
        void    checkYear(size_t const& lenght, std::string line);
        std::pair<std::string, float>    checkDateBitcF(std::string const& line);
        bool    isValidDate(const std::string& date);
        int     getYear(std::string date);
        void    checkErrors(std::string first, float second);
        std::string  returnValue(std::string line, size_t pos);
        void    parseFile();
        void    parseData();
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange& operator=(BitcoinExchange const& other);
        BitcoinExchange(std::string const& file);
        ~BitcoinExchange();
        void    displayBitcoins();
};

#endif