#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    //vector<string> input = {"a","b","ba","bca","bda","bdca"};
    //vector<string> input = {"sgtnz","sgtz","sgz","ikrcyoglz","ajelpkpx","ajelpkpxm","srqgtnz","srqgotnz","srgtnz","ijkrcyoglz"};
    vector<string> input = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    cout << test->longestStrChain(input) << endl;
    return 0;
}

