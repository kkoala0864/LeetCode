#include <Solution.h>
#include <iostream>

using namespace std;

void connectLeftToRight(TreeLinkNode* node) {
    if (nullptr == node->left || nullptr == node->right) {
	return;
    }

    connectLeftToRight(node->left);
    connectLeftToRight(node->right);
    TreeLinkNode* leftMostRight = node->left;
    TreeLinkNode* rightMostLeft = node->right;
    while (leftMostRight != nullptr) {
	leftMostRight->next = rightMostLeft;
	leftMostRight = leftMostRight->right;
	rightMostLeft = rightMostLeft->left;
    }
}

void Solution::connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    connectLeftToRight(root);
}
