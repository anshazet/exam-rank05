#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
private:
    std::string _name;
    std::string _title;

    Warlock();
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

public:
    // Constructor that takes its name and title
    Warlock(const std::string& name, const std::string& title);

    ~Warlock();
    
    const std::string& getName() const; // Getters returns a reference to constant string
    const std::string& getTitle() const; // Both will have to be callable on a constant Warlock.

    // Setter returns void and takes a reference to constant string
    void setTitle(const std::string& title);

    // Introduce function
    void introduce() const;
};

#endif

/*
class Warlock
{
private:
    std::string _name;
    std::string _title;

public:
    // Constructor that takes its name and title
    Warlock(const std::string& name, const std::string& title);

    // Destructor
    ~Warlock();

    // Deleted copy constructor and copy assignment operator
    Warlock(const Warlock& other) = delete;
    Warlock& operator=(const Warlock& other) = delete;

    // Getters
    const std::string& getName() const;
    const std::string& getTitle() const;

    // Setter
    void setTitle(const std::string& title);

    // Introduce function
    void introduce() const;
};

*/