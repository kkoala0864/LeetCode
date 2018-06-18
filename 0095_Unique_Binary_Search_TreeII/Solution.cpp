#include <Solution.h>
#include <iostream>

using namespace std;

vector<TreeNode*> genBST(int start, int end) {
    vector<TreeNode*> ret;
    if (end < start) {
	ret.emplace_back(nullptr);
	return ret;;
    }

    for (int i = start ; i <= end ; ++i) {
	vector<TreeNode*> leftSubTree = genBST(start, i-1);
	vector<TreeNode*> rightSubTree = genBST(i+1, end);

	for (int lIdx = 0 ; lIdx < leftSubTree.size() ; ++lIdx) {
	    for (int rIdx = 0 ; rIdx < rightSubTree.size() ; ++rIdx) {
		TreeNode* root = new TreeNode(i);
		root->left = leftSubTree.at(lIdx);
		root->right = rightSubTree.at(rIdx);
		ret.emplace_back(root);
	    }
	}
    }
    return ret;
}

vector<TreeNode*> Solution::generateTrees(int n) {
    if (0 == n) return vector<TreeNode*>();
    return genBST(1, n);
}
