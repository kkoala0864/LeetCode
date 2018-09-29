#include <Solution.h>
#include <queue>

using std::queue;

void convert(TreeNode* node, vector<TNode*>& CM) {
    if (nullptr == node) return;

    if (CM.at(node->val) == nullptr) {
	CM.at(node->val) = new TNode(node, nullptr);
    }

    TNode* leftChild = node->left ? new TNode(node->left, CM.at(node->val)) : nullptr;
    TNode* rightChild = node->right ? new TNode(node->right, CM.at(node->val)) : nullptr;
    leftChild ? CM.at(node->left->val) = leftChild : nullptr;
    rightChild ? CM.at(node->right->val) = rightChild : nullptr;

    CM.at(node->val)->left = leftChild;
    CM.at(node->val)->right = rightChild;

    convert(node->left, CM);
    convert(node->right, CM);
}

void BFS(TNode* node, const int& K, vector<int>& res) {
    queue<TNode*> que;
    que.emplace(node);
    int count(K);
    queue<TNode*> next;
    vector<bool> flags(501, true);
    flags.at(node->val) = false;

    while (!que.empty()) {
	if (count == 0) break;
	TNode* cur = que.front();
	que.pop();
	if (cur->left && flags.at(cur->left->val)) {
	   next.emplace(cur->left);
	   flags.at(cur->left->val) = false;
	}
	if (cur->right && flags.at(cur->right->val)) {
	   next.emplace(cur->right);
	   flags.at(cur->right->val) = false;
	}
	if (cur->parent && flags.at(cur->parent->val)) {
	    next.emplace(cur->parent);
	    flags.at(cur->parent->val) = false;
	}
	if (que.empty()) {
	    que = move(next);
	    --count;
	}
    }
    while (!que.empty()) {
	TNode* fnt = que.front();
	que.pop();
	res.emplace_back(fnt->val);
    }
}

vector<int> Solution::distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;
    vector<TNode*> convertMap(501, nullptr);
    convert(root, convertMap);

    BFS(convertMap.at(target->val), K, res);
    return res;
}
