#ifndef __SOLUTION_H__
#define __SOLUITON_H__
#include <cstddef>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public :
		Solution();
		TreeNode* invertTree(TreeNode* root);
		void DebugPrint(TreeNode* root);
	private :
		virtual ~Solution();
		Solution(const Solution&);
		Solution& operator=(const Solution& source);
};



#endif /* __SOLUTION_H__ */
