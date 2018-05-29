#include <Solution.h>
#include <iostream>
#include <list>
#include <vector>
#include <climits>

using namespace std;

bool Solution::isSymmetric(TreeNode* root) {
    if (nullptr == root) {
	return true;
    }

    list<pair<TreeNode*, int>> traverse;
    traverse.push_back(make_pair(root->left == nullptr ? new TreeNode(INT_MAX) : root->left, 2));
    traverse.push_back(make_pair(root->right == nullptr ? new TreeNode(INT_MAX) : root->right, 2));

    while (!traverse.empty()) {
	int depth = traverse.front().second;

	vector<int> checkSym;
	while (!traverse.empty() && traverse.front().second == depth) {
	    TreeNode* iter = traverse.front().first;
	    traverse.pop_front();
	    checkSym.push_back(iter->val);

	    if (iter->val == INT_MAX) {
		continue;
	    }
	    traverse.push_back(make_pair(nullptr == iter->left ? new TreeNode(INT_MAX) : iter->left, depth + 1));
	    traverse.push_back(make_pair(nullptr == iter->right ? new TreeNode(INT_MAX) : iter->right, depth + 1));
	}
	for (int i = 0, j = checkSym.size() - 1;  i < j ; ++i, --j) {
	    if (checkSym.at(i) != checkSym.at(j)) {
		return false;
	    }
	}
    }
    return true;
}

bool isSymTree(TreeNode* LeftNode, TreeNode* RightNode) {
    if (nullptr == LeftNode && nullptr == RightNode) {
	return true;
    }

    if (nullptr == LeftNode || nullptr == RightNode || LeftNode->val != RightNode->val) {
	return false;
    }

    return isSymTree(LeftNode->left, RightNode->right) && isSymTree(LeftNode->right, RightNode->left);
}

bool Solution::isSymmetricRecur(TreeNode* root) {
    return root == nullptr || isSymTree(root->left, root->right);
}
