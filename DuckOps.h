/* vim: tw=80:noet:sw=8:ts=8:sts=-1 */
#ifndef DUCK_OPS_H_
#define DUCK_OPS_H_

#include "DuckTraits.h"

namespace DuckOps
{
template <typename T>
void DoQuack(T &t, typename std::enable_if<DuckTraits::Quacks<T>::value>::type* = nullptr)
{
	t.Quack();
}

template <typename T>
void DoQuack(T &t, typename std::enable_if<DuckTraits::DoesntQuack<T>::value>::type* = nullptr)
{
	static_assert(DuckTraits::Quacks<T>::value, "Must be able to quack!");
}
} /* DuckOps */

#endif /* DUCK_OPS_H_ */
