#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    //vector<string> source = {"a/*comment", "line", "more_comment*/b"};
    for (const auto& idx : source) {
	cout << idx << endl;
    }
    Solution* test = new Solution();
    vector<string> ret = test->removeComments(source);
    cout << endl;
    for (const auto& idx : ret) {
	cout << idx << endl;
    }
    vector<string> golden = {"int main()","{ ","  ","int a, b, c;","a = b + c;","}"};

    cout << endl;
    for (const auto& idx : golden) {
	cout << idx << endl;
    }
    return 0;
}

