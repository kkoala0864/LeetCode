#include <Solution.h>
#include <iostream>
#include <queue>

using namespace std;

void Solution::connect(TreeLinkNode *root) {
    if (!root) return;
    queue<TreeLinkNode*> traverseQ;
    traverseQ.emplace(root);
    int cur_lv(1);
    int next_lv(0);
    while (!traverseQ.empty()) {
	while (cur_lv > 0) {
	    TreeLinkNode* cur_node = traverseQ.front();
	    traverseQ.pop(); --cur_lv;
	    if (cur_lv > 0)
		cur_node->next = traverseQ.front();
	    if (cur_node->left) {
		traverseQ.emplace(cur_node->left);
		++next_lv;
	    }
	    if (cur_node->right) {
		traverseQ.emplace(cur_node->right);
		++next_lv;
	    }
	}
	cur_lv = next_lv;
	next_lv = 0;
    }
}
