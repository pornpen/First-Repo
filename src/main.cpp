#include <iostream>
#include "LocCounter.hpp"

using namespace std;

int main()
{
	LocCounter locCounter;
	int count = locCounter.loc_count();
	cout << count << endl;
	return 0;
}
