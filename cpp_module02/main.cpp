#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"

// c++ -Wall -Wextra -Werror -std=c++98 main.cpp Warlock.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp Fireball.cpp Polymorph.cpp BrickWall.cpp SpellBook.cpp TargetGenerator.cpp


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


// Test 1: Forgetting a Spell Not Learned
// Test if your Warlock handles attempts to forget spells that were not learned
// without causing errors or affecting other spells.

// int main()
// {
//     Warlock richard("Richard", "the Titled");
//     richard.introduce();

//     Fwoosh fwoosh;
//     richard.learnSpell(&fwoosh);
//     richard.forgetSpell("InexistentSpell"); // Should not cause any issue
//     richard.launchSpell("Fwoosh", Dummy());

//     return 0;
// }


// Test 2: Multiple Spells and Targets
// Ensure your Warlock can handle multiple spells and targets correctly,
// including learning, forgetting, and launching spells on different targets.
/*
int main()
{
    Warlock richard("Richard", "the Titled");
    TargetGenerator tarGen;

    Fwoosh* fwoosh = new Fwoosh();
    Fireball* fireball = new Fireball();
    Polymorph* polymorph = new Polymorph();
    
    Dummy dummy;
    BrickWall wall;

    tarGen.learnTargetType(&dummy);
    tarGen.learnTargetType(&wall);

    richard.learnSpell(fwoosh);
    richard.learnSpell(fireball);
    richard.learnSpell(polymorph);

    ATarget* targetDummy = tarGen.createTarget("Target Practice Dummy");
    ATarget* targetWall = tarGen.createTarget("Inconspicuous Red-brick Wall");

    richard.introduce();
    richard.launchSpell("Fwoosh", *targetDummy);
    richard.launchSpell("Fireball", *targetWall);
    richard.launchSpell("Polymorph", *targetDummy);

    delete fwoosh;
    delete fireball;
    delete polymorph;
    delete targetDummy;
    delete targetWall;

    return 0;
}
*/

// Test 3: Re-Learning and Forgetting Spells
// Check if re-learning a spell that is already known and then forgetting it
// behaves as expected.
/*
int main()
{
    Warlock richard("Richard", "the Titled");

    Fwoosh fwoosh;
    richard.learnSpell(&fwoosh);
    richard.learnSpell(&fwoosh); // Re-learn the same spell
    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", Dummy()); // No effect expected

    return 0;
}
*/

// Test 4: Dynamic Allocation and Deallocation
// Verify that dynamically allocated spells and targets are managed
// properly without memory leaks.

/*
int main()
{
    Warlock richard("Richard", "the Titled");
    TargetGenerator tarGen;

    tarGen.learnTargetType(new Dummy());
    tarGen.learnTargetType(new BrickWall());

    richard.learnSpell(new Fwoosh());
    richard.learnSpell(new Fireball());
    richard.learnSpell(new Polymorph());

    ATarget* target = tarGen.createTarget("Inconspicuous Red-brick Wall");
    richard.launchSpell("Fireball", *target);

    delete target; // Ensure proper deletion

    return 0;
}
*/

// Test 5: Clearing Spells and Targets
// Ensure that clearing all learned spells and targets does not lead to
// crashes or memory leaks.

// int main()
// {
//     Warlock richard("Richard", "the Titled");
//     TargetGenerator tarGen;

//     // Learn and forget multiple spells and targets
//     tarGen.learnTargetType(new Dummy());
//     tarGen.learnTargetType(new BrickWall());
//     tarGen.forgetTargetType("Dummy");
//     tarGen.forgetTargetType("BrickWall");

//     richard.learnSpell(new Fwoosh());
//     richard.learnSpell(new Fireball());
//     richard.forgetSpell("Fwoosh");
//     richard.forgetSpell("Fireball");

//     return 0;
// }

