#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
	uint32_t n = 43261596;
	cout << unsigned(test->reverseBits(n)) << endl;
    return 0;
}

