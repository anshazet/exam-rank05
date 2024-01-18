#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"
#include "Fireball.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"

//  c++ -Wall -Wextra -Werroanastasia@MacBook-Pro-de-Anastasia cpp_module02 % c++ -Wall -Wextra -Werror -std=c++11 main.cpp Warlock.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp Fireball.cpp Polymorph.cpp BrickWall.cpp SpellBook.cpp TargetGenerator.cpp

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}