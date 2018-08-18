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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

