#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
public:
	Fireball();
	virtual~Fireball();
	virtual Fireball *clone()const;

};

#endif