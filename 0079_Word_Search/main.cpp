#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();

    vector< vector<char> > input;
    string inputw("ABCCED");
    vector<char> one, two, three;
    one.push_back('A');
    one.push_back('B');
    one.push_back('C');
    one.push_back('E');
    two.push_back('S');
    two.push_back('F');
    two.push_back('C');
    two.push_back('S');
    three.push_back('A');
    three.push_back('D');
    three.push_back('E');
    three.push_back('E');
    input.push_back(one);
    input.push_back(two);
    input.push_back(three);
    cout << test->exist(input,inputw) << endl;
    return 0;
}

