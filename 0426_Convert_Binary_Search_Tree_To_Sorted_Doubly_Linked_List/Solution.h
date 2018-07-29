#include <vector>

class Node {
    public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val, Node* _left, Node* _right) : val(_val) {
	    left = _left;
	    right = _right;
	}
};

class Solution {
    public :
        Solution() {}
	Node* treeToDoublyList(Node* root);
	Node* treeToDoublyListLL(Node* root);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

