/* vim: tw=80:noet:sw=8:ts=8:sts=-1 */
#ifndef DUCK_H_
#define DUCK_H_

#include <iostream>

struct Duck
{
	void Quack() const { std::cout << "Quack" << std::endl; }
};


struct RoboDuck
{
	void Quack() const { std::cout << "Robotic quack" << std::endl; }
};


struct NotDuck {};


namespace DuckTraits
{
template <typename T> struct Quacks : std::false_type {};
template <> struct Quacks<Duck> : std::true_type {};
template <> struct Quacks<RoboDuck> : std::true_type {};


template <typename T> struct DoesntQuack : std::true_type {};
template <> struct DoesntQuack<Duck> : std::false_type {};
template <> struct DoesntQuack<RoboDuck> : std::false_type {};
} /* DuckTraits */


namespace DuckOps
{
template <typename T>
void DoQuack(const T &t, typename std::enable_if<DuckTraits::Quacks<T>::value>::type* = nullptr)
{
	t.Quack();
}


template <typename T>
void DoQuack(const T &t, typename std::enable_if<DuckTraits::DoesntQuack<T>::value>::type* = nullptr)
{
	static_assert(DuckTraits::Quacks<T>::value, "Must be able to quack!");
}
} /* DuckOps */

#endif /* DUCK_H_ */
