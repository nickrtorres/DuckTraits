#ifndef DUCK_TRAITS_H_
#define DUCK_TRAITS_H_

struct Duck;
struct RoboDuck;

namespace DuckTraits
{
template <typename T> struct Quacks : std::false_type {};
template <> struct Quacks<Duck> : std::true_type {};
template <> struct Quacks<RoboDuck> : std::true_type {};

template <typename T> struct DoesntQuack : std::true_type {};
template <> struct DoesntQuack<Duck> : std::false_type {};
template <> struct DoesntQuack<RoboDuck> : std::false_type {};
}

#endif  /* DUCK_TRAITS_H_ */
