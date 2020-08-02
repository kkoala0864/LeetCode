#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<vector<int>> Solution::levelOrder(Node* root) {
	queue<Node*> curQ, nextQ;

	vector<vector<int>> ret;
	vector<int> curRet;

	if (!root) return ret;
	curQ.emplace(root);

	while (!curQ.empty()) {
		Node* curNode = curQ.front();
		curRet.emplace_back(curNode->val);
		for (auto iter : curNode->children) {
			nextQ.emplace(iter);
		}
		curQ.pop();
		if (curQ.empty()) {
			ret.emplace_back(curRet);
			curRet.clear();
			curQ = move(nextQ);
		}
	}
	return ret;
}
