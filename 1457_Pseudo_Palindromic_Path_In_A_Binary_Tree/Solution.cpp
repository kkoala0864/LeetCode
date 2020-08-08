#include <Solution.h>
#include <iostream>

void traverse(TreeNode* node, int& count, int& record, int& pathSize) {
	if (nullptr == node) {
		return;
	}

	int num = 1 << node->val;
	record = record ^ num;
	++pathSize;
	if (nullptr == node->left && nullptr == node->right) {
		if (pathSize & 1) {
			int oneCnt(0);
			int checkNum(record);
			for (int i = 0 ; i < 9 ; ++i) {
				checkNum = checkNum >> 1;
				if (checkNum & 1) ++oneCnt;
				if (oneCnt > 1) break;
			}
			if (oneCnt == 1) ++count;
		} else {
			if (0 == record) ++count;
		}
	} else {
		traverse(node->left, count, record, pathSize);
		traverse(node->right, count, record, pathSize);
	}
	record = record ^ num;
	--pathSize;
}

int Solution::pseudoPalindromicPaths (TreeNode* root) {
	int count(0);
	int record(0);
	int pathSize(0);
	traverse(root, count, record, pathSize);
	return count;
}
