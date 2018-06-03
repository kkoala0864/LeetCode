#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    cout << test->numSquares(52) << endl;
    cout << test->numSquares4SquaresTheory(52) << endl;
    //cout << test->numSquares(1) << endl;

    return 0;
}

