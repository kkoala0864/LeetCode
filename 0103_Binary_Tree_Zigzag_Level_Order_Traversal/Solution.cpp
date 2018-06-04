#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (nullptr == root) {
	return ret;
    }

    queue<pair<TreeNode*, int>> record;
    record.push(make_pair(root, 1));
    while (!record.empty()) {
	vector<int> cur_level;
	int level = record.front().second;
	while (!record.empty() && level == record.front().second) {
	    TreeNode* iter = record.front().first;
	    record.pop();
	    if (iter->left != nullptr) {
		record.push(make_pair(iter->left, level + 1));
	    }
	    if (iter->right != nullptr) {
		record.push(make_pair(iter->right, level + 1));
	    }
	    cur_level.emplace_back(iter->val);
	}
	if (!(level & 1)) {
	    ret.emplace_back(cur_level.rbegin(), cur_level.rend());
	} else {
	    ret.emplace_back(cur_level);
	}
    }
    return ret;
}

