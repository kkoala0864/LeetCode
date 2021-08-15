#include <string>
#include <vector>
using std::string;
using std::vector;

struct Node {
	vector<Node*> Next;
	bool Word;
	Node() {
		Next = vector<Node*>(26, nullptr);
		Word = false;
	}
};

class Solution {
    public :
        Solution();
	void addWord(string word);
	bool search(string word);
    private :
	Node *root = nullptr;
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

