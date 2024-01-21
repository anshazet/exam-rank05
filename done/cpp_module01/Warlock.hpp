#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
	std::string _name;
	std::string _title;
	std::map<std::string, ASpell*> _spell;

	Warlock();
	Warlock(const Warlock& other);
	Warlock& operator=(const Warlock& other);

public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();
	const std::string& getName()const;
	const std::string& getTitle()const;

	void setTitle(const std::string &title);

	void introduce() const;

	void learnSpell(ASpell* spell);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, const ATarget &target);
};

#endif

// * learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
// * forgetSpell, takes a string corresponding a to a spell's name, and makes the
//   Warlock forget it. If it's not a known spell, does nothing.
// * launchSpell, takes a string (a spell name) and a reference to ATarget, that
//   launches the spell on the selected target. If it's not a known spell, does
//   nothing.