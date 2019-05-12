#include <Solution.h>

bool check(TreeNode* node1, TreeNode* node2) {
    if (node1 == node2) return true;
    if (node1 == NULL || node2 == NULL) return false;
    if (node1->val != node2->val) return false;
    return node1->val == node2->val;
}

bool compare(TreeNode* node1, TreeNode* node2) {
    if (node1 == NULL && node2 == NULL) return true;
    if (check(node1->left, node2->left) && check(node1->right, node2->right)) {
	return compare(node1->left, node2->left) && compare(node1->right, node2->right);
    } else if (check(node1->left, node2->right) && check(node1->right, node2->left)) {
	TreeNode* tmp = node2->left;
	node2->left = node2->right;
	node2->right = tmp;
	return compare(node1->left, node2->left) && compare(node1->right, node2->right);
    } else {
	return false;
    }
}

bool Solution::flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!check(root1, root2)) return false;
    return compare(root1, root2);
}
