#include <Solution.h>
#include <iostream>

using namespace std;

int main(void) {
    //vector<string> word = {"oath","pea","eat","rain"};
    //vector<vector<char>> board = {
    //    {'o','a','a','n'},
    //    {'e','t','a','e'},
    //    {'i','h','k','r'},
    //    {'i','f','l','v'}
    //};
    vector<string> word = {"aaa"};
    vector<vector<char>> board = {
	{'a'},
	{'a'}
    };
    Solution* test = new Solution();
    vector<string> ret = test->findWords(board, word);
    for (const auto& ch : ret) {
	cout << ch << " ";
    }
    cout << endl;

    return 0;
}

