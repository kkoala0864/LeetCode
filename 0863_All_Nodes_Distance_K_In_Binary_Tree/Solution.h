#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TNode {
    int val;
    TNode* left;
    TNode* right;
    TNode* parent;
    TNode(TreeNode* x, TNode* y) : val(x->val), parent(y) {}
};

class Solution {
    public :
        Solution() {}
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

