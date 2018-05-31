#include <Solution.h>
#include <iostream>
#include <list>

using namespace std;

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (nullptr == root) {
	return ret;
    }

    list<TreeNode*> queue;
    queue.emplace_back(root);
    int current_lv(1);
    int next_lv(0);
    vector<int> lv_val;

    while (!queue.empty()) {
	TreeNode* iter = queue.front();
	queue.pop_front();
	--current_lv;
	lv_val.emplace_back(iter->val);
	if (iter->left != nullptr) {
	    queue.emplace_back(iter->left);
	    ++next_lv;
	}
	if (iter->right != nullptr) {
	    queue.emplace_back(iter->right);
	    ++next_lv;
	}

	if (0 == current_lv) {
	    current_lv = next_lv;
	    next_lv = 0;
	    ret.emplace_back(lv_val);
	    lv_val.clear();
	}
    }
    return ret;
}
