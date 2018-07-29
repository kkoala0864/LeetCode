#include <Solution.h>
#include <iostream>

using namespace std;

// left node right point to parent
// right node left point to parent
// right node right if null should point back to grandparent
// only leaf should special handle
// Q is How do I know the Most Left or Most Right
void convert(Node* parent, Node* node, Node*& MostRight, Node*& MostLeft, int direct) {
    if (node->left == nullptr && node->right == nullptr) {
	node->left = parent;
	node->right = parent;
	MostLeft = node;
	MostRight = node;
	return;
    }

    Node* LML = node;
    Node* LMR = node;
    Node* RML = node;
    Node* RMR = node;

    if (node->left)
	convert(node, node->left, LMR, LML, 1);
    if (node->right)
	convert(node, node->right, RMR, RML, 2);

    MostRight = RMR;
    MostLeft = LML;
    if (LMR != node) {
	LMR->right = node;
	node->left = LMR;
    }
    if (RML != node) {
	node->right = RML;
	RML->left = node;
    }
}

Node* Solution::treeToDoublyList(Node* root) {
    if (root == nullptr) return root;

    if (root->left == nullptr && root->right == nullptr) {
	root->left = root;
	root->right = root;
	return root;
    }

    Node* LML = root;
    Node* LMR = root;
    Node* RML = root;
    Node* RMR = root;

    if (root->left)
	convert(root, root->left, LMR, LML, 1);
    if (root->right)
	convert(root, root->right, RMR, RML, 2);

    LML->left = RMR;
    RMR->right = LML;

    if (LMR != root) {
	LMR->right = root;
	root->left = LMR;
    }
    if (RML != root) {
	root->right = RML;
	RML->left = root;
    }
    return LML;
}

void convertLL(Node* root, Node*& prev, Node*& head) {
    if (root == nullptr) return;
    convertLL(root->left, prev, head);
    if (head == nullptr) {
	head = root;
    } else {
	root->left = prev;
	prev->right = root;
    }
    prev = root;
    convertLL(root->right, prev, head);
}

Node* Solution::treeToDoublyListLL(Node* root) {
    Node* prev = nullptr;
    Node* head = nullptr;
    convertLL(root, prev, head);
    if (head) {
	head->left = prev;
	prev->right = head;
    }
    return head;
}
