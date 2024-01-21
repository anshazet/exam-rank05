#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string _name;
	std::string _effects;

public:
	ASpell();
	ASpell(const std::string &name, const std::string &effects);
	ASpell(const ASpell& other);
	ASpell& operator=(const ASpell& other);
	virtual ~ASpell();

	const std::string& getName()const;
	const std::string& getEffects()const;

	virtual ASpell *clone() const = 0; //clone pure method that returns a pointer to ASpell

	void launch(const ATarget &target) const; //takes a reference to constant ATarget


};

#endif