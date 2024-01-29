#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it;
	for (it = _target.begin(); it != _target.end(); ++it)
	{
		delete it->second;
	}
	_target.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		_target[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string &type)
{
	std::map<std::string, ATarget *>::iterator it = _target.find(type);
	if (it != _target.end())
		delete it->second;
	_target.erase(it);
}

ATarget *TargetGenerator::createTarget(const std::string &type)
{
	std::map<std::string, ATarget *>::const_iterator it = _target.find(type);
	if (it != _target.end())
	{
		return it->second->clone();
	}
	return NULL;
}
