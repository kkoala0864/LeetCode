#include <cstddef>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		Solution() {};
		int maxDepth(TreeNode* root);
		void DebugPrint();
	private:
		virtual ~Solution() {};
		Solution(const Solution&);
		Solution& operator=(const Solution& source);
};
