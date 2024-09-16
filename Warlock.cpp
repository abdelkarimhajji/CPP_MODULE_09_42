#include "Warlock.hpp"

 std::string const & Warlock::getName() const
{
    return this->name;
}
std::string const & Warlock::getTitle() const
{
    return this->title;
}
void    Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

Warlock::Warlock(Warlock const &other)
{
    this->name = other.name;
    this->title = other.title;
}

Warlock& Warlock::operator=(Warlock const &other)
{
    this->name = other.name;
    this->title = other.title;
    return *this;
}
void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
    
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}