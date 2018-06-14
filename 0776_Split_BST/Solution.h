#include <vector>

using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public :
        Solution() {}
	vector<TreeNode*> splitBST(TreeNode* root, int V);
	vector<TreeNode*> splitBST2(TreeNode* root, int V);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

