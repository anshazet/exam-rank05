#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell*>::iterator    it = _spell.begin();
    std::map<std::string, ASpell*>::iterator    ite = _spell.end();
    while (it != ite)
    {
        delete it->second;
        ++it;
    }
    _spell.clear();
}

void    SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
    {
        _spell.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
    }
}
void    SpellBook::forgetSpell(std::string const &spell)
{
    std::map<std::string, ASpell*>::iterator    it = _spell.find(spell);
    if (it != _spell.end())
    {
        delete it->second;
    }
    _spell.erase(spell);
}

ASpell  *SpellBook::createSpell(std::string const &spell)
{
    std::map<std::string, ASpell*>::iterator    it = _spell.find(spell);
    if (it != _spell.end())
        return _spell[spell];
    return(NULL);
}