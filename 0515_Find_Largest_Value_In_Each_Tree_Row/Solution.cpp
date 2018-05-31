#include <Solution.h>
#include <iostream>
#include <list>
#include <climits>

using namespace std;

vector<int> largestValues(TreeNode* root) {
    vector<int> ret;
    if (nullptr == root) {
	return ret;
    }

    list<TreeNode*> queue;
    queue.push_back(root);
    int current_lv(1);
    int next_lv(0);
    int max(INT_MIN);
    while (!queue.empty()) {

	TreeNode* iter = queue.front();
	queue.pop_front();
	--current_lv;

	if (iter->val > max) {
	    max = iter->val;
	}
	if (iter->left) {
	    queue.push_back(iter->left);
	    ++next_lv;
	}
	if (iter->right) {
	    queue.push_back(iter->right);
	    ++next_lv;
	}

	if (0 == current_lv) {
	    current_lv = next_lv;
	    next_lv = 0;
	    ret.push_back(max);
	    max = INT_MIN;
	}
    }
    return ret;
}
