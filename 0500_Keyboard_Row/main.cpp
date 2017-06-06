#include <Solution.h>
#include <iterator>
#include <iostream>

using namespace std;
int main(void) {
    Solution* test = new Solution();
    vector<string> tmp;

    vector<string> input = {"Hello", "Alaska", "Dad", "Peace"};

    tmp = test->findWords(input);
    cout << tmp.size() << endl;
    for (vector<string>::iterator iter = tmp.begin() ; iter != tmp.end() ; ++iter) {
	cout << *iter << endl;
    }
    return 0;
}

