#include <Solution.h>
#include <iostream>
int main() {


	TreeNode* node1 = new TreeNode(4);
	TreeNode* node2 = new TreeNode(2);
//	TreeNode* node3 = new TreeNode(7);
//	TreeNode* node4 = new TreeNode(1);
//	TreeNode* node5 = new TreeNode(3);
//	TreeNode* node6 = new TreeNode(6);
//	TreeNode* node7 = new TreeNode(9);

	node1->left = NULL;
	node1->right = node2;
//	node2->left = node4;
//	node2->right = node5;
//	node3->left = node6;
//	node3->right = node7;
	Solution test1;
	test1.DebugPrint(node1);
	std::cout << std::endl;
	test1.invertTree(node1);
	std::cout << std::endl;
	test1.DebugPrint(node1);
}
