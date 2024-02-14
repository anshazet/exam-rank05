#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
	Polymorph();
	virtual~Polymorph();
	virtual Polymorph *clone()const;
//	ASpell *clone()const;
};

#endif