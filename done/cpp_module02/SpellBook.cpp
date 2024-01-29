#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it;
	for (it = _spell.begin(); it != _spell.end(); ++it)
	{
		delete it->second;
	}
	_spell.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		_spell[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(const std::string &name)
{
	std::map<std::string, ASpell *>::iterator it = _spell.find(name);
	if (it != _spell.end())
		delete it->second;
	_spell.erase(it);
}

ASpell *SpellBook::createSpell(const std::string &name)
{
	std::map<std::string, ASpell *>::const_iterator it = _spell.find(name);
	if (it != _spell.end())
	{
		return it->second->clone();
	}
	return NULL;
}