#include <Solution.h>
#include <iostream>
#include <queue>
#include <stack>
using std::cout;
using std::endl;
using std::queue;
using std::stack;

void output(TreeNode* node) {
    queue<TreeNode*> que;
    que.push(node);

    while (!que.empty()) {
	TreeNode* tmp = que.front();
	que.pop();
	if (tmp) {
	    cout << tmp->val << " ";
	    if (tmp->left || tmp->right) {
		que.push(tmp->left);
		que.push(tmp->right);
	    }
	} else {
	    cout << "null" << " ";
	}
    }
    cout << endl;
}

void appendNode(TreeNode*& node, const vector<int>& preorder, int start, int end) {
    if (start > end) return;

    int rootVal = preorder.at(start);
    node = new TreeNode(rootVal);
    int i = start + 1;
    for (; i <= end && rootVal > preorder.at(i) ; ++i) {}

    if (i <= end) {
	appendNode(node->left, preorder, start + 1, i - 1);
	appendNode(node->right, preorder, i, end);
    } else {
	appendNode(node->left, preorder, start + 1, end);
    }
}

void iteration(TreeNode*& node, const vector<int>& preorder) {
    int size = preorder.size();
    node = new TreeNode(preorder.at(0));
    stack<TreeNode*> stk;
    TreeNode* iterNode = node;

    for (int i = 1 ; i < size ; ++i) {
	int curVal = preorder.at(i);
	if (iterNode->val > curVal) {
	    iterNode->left = new TreeNode(curVal);
	    stk.push(iterNode);
	    iterNode = iterNode->left;
	} else {
	    while (!stk.empty() && (stk.top()->val < curVal)) {
		iterNode = stk.top();
		stk.pop();
	    }
	    while (iterNode && iterNode->right && iterNode->val < curVal) {
		iterNode = iterNode->right;
	    }
	    iterNode->right = new TreeNode(curVal);
	    stk.push(iterNode);
	    iterNode = iterNode->right;
	}
    }
}

TreeNode* Solution::bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty()) return NULL;
    TreeNode* root = NULL;
    iteration(root, preorder);
    output(root);
    return root;
}
