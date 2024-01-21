#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
	std::string _type;

public:
	ATarget();
	ATarget(const std::string &type);
	ATarget(const ATarget& other);
	ATarget& operator=(const ATarget& other);
	virtual ~ATarget();

	const std::string& getType()const;

	virtual ATarget *clone() const = 0; //pure virtuel

	void getHitBySpell(const ASpell &spell)const; //function that takes a reference to constant ASpell

};

#endif