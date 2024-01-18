#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
public:

    TargetGenerator();
    ~TargetGenerator();
	void learnTargetType(ATarget* target);
    void forgetTargetType(const std::string& target);
    ATarget* createTarget(const std::string& target);

private:

    TargetGenerator(TargetGenerator const &other);
    TargetGenerator &operator=(TargetGenerator const &t);
    std::map<std::string, ATarget*> _target;

	// TargetGenerator(const TargetGenerator& other);
	// TargetGenerator& operator=(const TargetGenerator& other);
};

#endif
