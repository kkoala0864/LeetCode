#include <iostream>
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public :
        Solution() {}
	int distributeCoins(TreeNode* root);
	int distributeCoinsII(TreeNode* root);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

