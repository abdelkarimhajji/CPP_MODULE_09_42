/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:00:56 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/29 13:30:42 by ahajji           ###   ########.fr       */
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
#include <utility>

class BitcoinExchange
{
    private:
        std::string nameFile;
        std::map<std::string, float> database;
        std::map<std::string, float> dataValue;
        void    errorParse(int state);
        void    checkDateBitc(std::string const& line);
        void    checkDate(std::string const& line);
        void    checkDay(size_t const& lenght, std::string line);
        void    checkMonth(size_t const& lenght, std::string line);
        void    checkYear(size_t const& lenght, std::string line);
        std::pair<std::string, float>    checkDateBitcF(std::string const& line);
        void    checkDateF(std::string const& line, int state);
        void    checkDayF(size_t const& lenght, std::string line, int state);
        void    checkMonthF(size_t const& lenght, std::string line);
        void    checkYearF(size_t const& lenght, std::string line);
        bool    isValidDate(const std::string& date);
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