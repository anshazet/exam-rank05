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

void    Warlock::learnSpell(ASpell *spell)
{
    _book.learnSpell(spell);
}

void    Warlock::forgetSpell(std::string name)
{
    _book.forgetSpell(name);
}

void    Warlock::launchSpell(std::string name, ATarget const & target)
{
    ATarget const *test = 0;
    if (test == &target)
        return;
    ASpell  *tmp = _book.createSpell(name);
    if (tmp)
        tmp->launch(target);
}