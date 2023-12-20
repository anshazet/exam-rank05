#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(const std::string &name, const std::string &title)
    : _name(name), _title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
    return _name;
}

const std::string &Warlock::getTitle() const
{
    return _title;
}

void Warlock::setTitle(const std::string &title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

// Preventing copying
Warlock::Warlock(const Warlock &other) : _name(""), _title("")
{
    (void)other;
}

Warlock &Warlock::operator=(const Warlock &other)
{
    (void)other;
    return *this;
}
