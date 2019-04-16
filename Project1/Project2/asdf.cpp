#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "MemoryMonster.h"

using namespace std;

int main()
{
	vector<MemoryMonster> monsters{ 3, 1, 7, 9, 5 };

	sort(monsters.begin(), monsters.end());
}
