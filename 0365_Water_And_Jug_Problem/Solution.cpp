#include <Solution.h>
#include <iostream>

using namespace std;

// ax + by = z
// gcd(x,y) = d
// z % d = 0
int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x%y);
}

bool Solution::canMeasureWater(int x, int y, int z) {
    if (0 == z) return true;
    if (x+y >= z) {
	return z % gcd(x,y) == 0;
    } else {
	return false;
    }
}
