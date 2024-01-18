#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
    std::string _name;
    std::string _title;
    SpellBook _book; // Instance of SpellBook
    
    Warlock();
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

public:
    // Constructor that takes its name and title
    Warlock(const std::string& name, const std::string& title);

    ~Warlock();
    
    const std::string& getName() const; // Getters returns a reference to constant string
    const std::string& getTitle() const; // Both will have to be callable on a constant Warlock.

    
    void setTitle(const std::string& title); // returns void and takes a reference to constant string

    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(std::string name);
    void launchSpell(std::string name, ATarget const & target);
};

#endif
