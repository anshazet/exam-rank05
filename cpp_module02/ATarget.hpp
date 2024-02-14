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
	ATarget(const ATarget& other);
	ATarget& operator=(const ATarget& other);

	ATarget(const std::string &type);
	virtual~ATarget();
	virtual ATarget *clone()const = 0;
	const std::string& getType()const;
	void getHitBySpell(const ASpell &spell)const;
};

#endif