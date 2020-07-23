#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

void pushToVec(TreeNode* root, vector<int>& tmp) {
	if (!root) return;
	pushToVec(root->right, tmp);
	tmp.emplace_back(root->val);
	pushToVec(root->left, tmp);
}

vector<int> Solution::getAllElements(TreeNode* root1, TreeNode* root2) {
	vector<int> root1tmp;
	vector<int> root2tmp;
	vector<int> ret;
	pushToVec(root1, root1tmp);
	pushToVec(root2, root2tmp);
	for (; !root1tmp.empty() && !root2tmp.empty();) {
		if (root1tmp.back() < root2tmp.back()) {
			ret.emplace_back(root1tmp.back());
			root1tmp.pop_back();
		} else if (root1tmp.back() > root2tmp.back()) {
			ret.emplace_back(root2tmp.back());
			root2tmp.pop_back();
		} else {
			ret.emplace_back(root1tmp.back());
			ret.emplace_back(root2tmp.back());
			root1tmp.pop_back();
			root2tmp.pop_back();
		}
	}
	if (!root1tmp.empty()) {
		ret.insert(ret.end(), root1tmp.rbegin(), root1tmp.rend());
	} else {
		ret.insert(ret.end(), root2tmp.rbegin(), root2tmp.rend());
	}
	return ret;
}
