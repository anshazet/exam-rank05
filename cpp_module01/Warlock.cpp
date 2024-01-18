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
    if (spell)
        _spell.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void    Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell*>::iterator    it = _spell.find(name);
    if (it != _spell.end())
        delete it->second;
    _spell.erase(name);
}

void    Warlock::launchSpell(std::string name, ATarget const & target)
{
    ASpell  *aspell = _spell[name];
    if (aspell)
        aspell->launch(target);
}

/*
void Warlock::forgetSpell(const std::string& name)
{
    auto it = spells.find(name);
    if (it != spells.end())
    {
        delete it->second;
        spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string& name, const ATarget& target)
{
    ASpell* spell = spells[name];
    if (spell)
    {
        spell->launch(target);
    }
}
*/
