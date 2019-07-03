#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    //string input = "L.....RR.RL.....L.R.";
    //string input = ".L.R...LR..L..";
    //string input = "RR.L";
    string input = "L.LL......";
    cout << test->pushDominoes(input) << endl;
    return 0;
}

