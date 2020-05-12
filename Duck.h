/* vim: tw=80:noet:sw=8:ts=8:sts=-1 */
#ifndef DUCK_H_
#define DUCK_H_

#include <iostream>

#include "DuckTraits.h"

struct Duck
{
	void Quack() const { std::cout << "Quack" << std::endl; }
};

struct RoboDuck
{
	void Quack() const { std::cout << "Robotic quack" << std::endl; }
};

struct NotDuck {};

#endif /* DUCK_H_ */
