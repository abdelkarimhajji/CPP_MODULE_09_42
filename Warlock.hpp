#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock
{
    private:
        Warlock();
        Warlock(Warlock const &other);
        Warlock& operator=(Warlock const &other);
        std::string name;
        std::string title;
    public:
        Warlock(std::string name, std::string title);
        std::string const & getName() const;
        std::string const &getTitle() const;
        void    setTitle(const std::string &tile);
        void	introduce() const;
        ~Warlock(); 
};

#endif