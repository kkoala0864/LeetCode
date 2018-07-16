#include <vector>
#include <string>
using std::vector;
using std::string;

struct TrieNode {
    vector<TrieNode*> children;
    string word;
    TrieNode() : children(26, nullptr) {}
};

class Solution {
    public :
        Solution() {}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

