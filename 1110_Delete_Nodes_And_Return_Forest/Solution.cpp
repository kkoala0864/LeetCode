#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void delete_node(TreeNode* node, const unordered_map<int, bool>& to_delete, vector<TreeNode*>& ret) {
	if (nullptr == node) {
		return;
	}

	TreeNode* leftChild = node->left;
	TreeNode* rightChild = node->right;

	if (leftChild && to_delete.find(leftChild->val) != to_delete.end()) {
		node->left = nullptr;
	}
	if (rightChild && to_delete.find(rightChild->val) != to_delete.end()) {
		node->right = nullptr;
	}

	if (to_delete.find(node->val) != to_delete.end()) {
		if (node->left && to_delete.find(node->left->val) == to_delete.end()) {
			ret.emplace_back(node->left);
		}
		if (node->right && to_delete.find(node->right->val) == to_delete.end()) {
			ret.emplace_back(node->right);
		}
		node->left = nullptr;
		node->right = nullptr;
	}
	delete_node(leftChild, to_delete, ret);
	delete_node(rightChild, to_delete, ret);
}

vector<TreeNode*> Solution::delNodes(TreeNode* root, vector<int>& to_delete) {
	unordered_map<int, bool> record;
	for (const auto& iter: to_delete) {
		record.emplace(iter, true);
	}

	vector<TreeNode*> ret;
	if (root && record.find(root->val) == record.end()) {
		ret.emplace_back(root);
	}
	delete_node(root, record, ret);
	return ret;
}
