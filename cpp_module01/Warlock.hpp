#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
private:
    std::string _name;
    std::string _title;

    // Private copy constructor and assignment operator to prevent copying
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

public:
    // Constructor
    Warlock(const std::string& name, const std::string& title);

    // Destructor
    ~Warlock();

    // Getters
    const std::string& getName() const;
    const std::string& getTitle() const;

    // Setter
    void setTitle(const std::string& title);

    // Introduce function
    void introduce() const;
};

#endif