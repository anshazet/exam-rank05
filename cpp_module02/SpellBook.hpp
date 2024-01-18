#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
private:

    std::map<std::string, ASpell*>  _spell;
    
    SpellBook(const SpellBook& other);
    SpellBook& operator=(const SpellBook& other);

public:
    // Constructor that takes its name and title
    SpellBook(const std::string& name, const std::string& title);
	SpellBook();
    ~SpellBook();

	void learnSpell(ASpell *spell);
    void forgetSpell(std::string const &spell);
    ASpell *createSpell(std::string const &spell);
};

#endif