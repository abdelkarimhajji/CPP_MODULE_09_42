/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:33:52 by ahajji            #+#    #+#             */
/*   Updated: 2024/08/27 16:41:51 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void    errorParse(int state)
{
    if(state == 0)
        std::cout << "error in arg" << std::endl;
    else if(state == 1)
        std::cout << "error in parse" << std::endl;
    std::exit(1);
}

void    checkDateBitc(std::string const& line)
{
    size_t pos = line.find('|');
    std::string number;
    long intNumber;
    if(pos != std::string::npos)
    {
        for(int i = pos + 1; i < line.length(); i++)
        {
            if((i == (pos + 1)) && line[i] != ' ')
                errorParse(1);
            // else if (i != (pos + 1) && std::isdigit(line[i]) == false && line[i] != '.')
            //     errorParse(1);
            // else if(line[i + 1] == '\0' && std::isdigit(line[i]) == false)
            //     errorParse(1);
            // number += line[i];
        }
        // std::stringstream str(number);
        // str >> intNumber;
        // if(intNumber > std::numeric_limits<int>::max())
        //     errorParse(1);
        // checkDate(line);
    }
    else
        errorParse(0);
}

int main()
{
    std::ifstream file("data.csv");
    std::string line;
    int count = 0;
    if(file.is_open())
    {
        while (std::getline(file, line))
        {
            for(int i = 0; i < line.length(); i++)
            {
                if(count == 0 && line != "date | value")
                {
                    std::cout << line << " this is i " << i<< "\n";                    
                    errorParse(1);
                }
                else if(count != 0)
                    checkDateBitc(line);
            }
            count++;
        }
    }
    else
    {
        errorParse(0);
    }
    return 0;
}