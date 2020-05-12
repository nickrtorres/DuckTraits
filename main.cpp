/* vim: tw=80:noet:sw=8:ts=8:sts=-1 */
#include "Duck.h"

int main()
{
#if GOOD
	Duck d;
	DuckOps::DoQuack(d);

	RoboDuck rd;
	DuckOps::DoQuack(rd);
#elif BAD
	NotDuck nd;
	DuckOps::DoQuack(nd);
#endif

	return 0;
}
