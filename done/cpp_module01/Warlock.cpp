#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
	: _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName()const
{
	return _name;
}

const std::string& Warlock::getTitle()const
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

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spell[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell*>::iterator it = _spell.find(name);
	if (it != _spell.end())
		delete it->second;
	_spell.erase(it);
}

void Warlock::launchSpell(std::string name, const ATarget &target)
{
	std::map<std::string, ASpell*>::const_iterator it = _spell.find(name);
	if (it != _spell.end())
		it->second->launch(target);
}

/*
Purpose: This function learns a new spell.
Process: If the spell is not null, it clones the spell and stores the clone
in the map _spell. The spell->getName() returns the name of the spell,
which is used as the key. The spell->clone() creates a dynamic copy of the spell,
stored as the value.

Purpose: This function forgets (or removes) a learned spell.
it->second: Here, it is an iterator pointing to the found spell in the map.
it->second is the value part of the pair, which in this case, is a pointer
to the ASpell object associated with the spell's name. When you do delete it->second;,
you're deallocating the memory for the cloned spell.
Note: It's important to check if it is not equal to _spell.end() before using it->second,
to ensure the spell was found in the map.

Purpose: This function launches a spell if it's known (learned).
it->second: Similar to forgetSpell, it->second in this context is the pointer
to the ASpell object. When you call it->second->launch(target);, you're invoking
the launch method on the spell object, targeting the specified ATarget.
*/