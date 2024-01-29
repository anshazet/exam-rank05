#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
	std::map<std::string, ASpell *> _spell;

	// Private copy constructor and assignment operator to prevent copying
	SpellBook(const SpellBook &other);
	SpellBook &operator=(const SpellBook &other);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &name);
	ASpell *createSpell(const std::string &name);
};

#endif
