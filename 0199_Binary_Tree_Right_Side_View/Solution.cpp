#include <Solution.h>
#include <iostream>
#include <list>

using namespace std;

vector<int> Solution::rightSideView(TreeNode* root) {
    vector<int> ret;
    if (nullptr == root) {
	return ret;
    }
    list<TreeNode*> queue;
    queue.emplace_back(root);

    int current_lv(1);
    int next_lv(0);

    while (!queue.empty()) {
	TreeNode* iter = queue.front();
	queue.pop_front();
	--current_lv;
	if (iter->left != nullptr) {
	    queue.emplace_back(iter->left);
	    ++next_lv;
	}
	if (iter->right != nullptr) {
	    queue.emplace_back(iter->right);
	    ++next_lv;
	}
	if (0 == current_lv) {
	    ret.emplace_back(iter->val);
	    current_lv = next_lv;
	    next_lv = 0;
	}
    }
    return ret;
}

void helper(TreeNode* node, int level, vector<int>& ret) {
    if (nullptr == node) {
	return;
    }
    if (ret.size() < level) {
	ret.emplace_back(node->val);
    } else {
	ret.at(level-1) = node->val;
    }
    helper(node->left, level + 1, ret);
    helper(node->right, level + 1, ret);
}

vector<int> Solution::rightSideViewRecur(TreeNode* root) {
    vector<int> ret;
    if (nullptr == root) {
	return ret;
    }

    helper(root, 1, ret);
    return ret;
}
