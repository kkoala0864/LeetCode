#include <Solution.h>
#include <iostream>

void dfs(int N, vector<vector<TreeNode*>>& map) {
    if (0 == N) {
	map.at(0).emplace_back(new TreeNode(0));
    } else if (2 == N) {
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(0);
	root->right = new TreeNode(0);
	map.at(2).emplace_back(root);
    } else {
	vector<TreeNode*> ret;
	int targetN = N - 2;
	for (int i = 0 ; i <= (targetN >> 1); i += 2) {
	    if (map.at(i).empty()) dfs(i, map);
	    if (map.at(N-i).empty()) dfs(targetN-i, map);
	    for (const auto leftIdx : map.at(i)) {
		for (const auto rightIdx : map.at(targetN-i)) {
		    TreeNode* root = new TreeNode(0);
		    root->left = leftIdx;
		    root->right = rightIdx;
		    ret.emplace_back(root);
		    if (i < (targetN >> 1)) {
			TreeNode* rootSwap = new TreeNode(0);
			rootSwap->left = rightIdx;
			rootSwap->right = leftIdx;
			ret.emplace_back(rootSwap);
		    }
		}
	    }
	}
	map.at(N) = ret;
    }
}

vector<TreeNode*> Solution::allPossibleFBT(int N) {
    if (0 == (N & 1)) return vector<TreeNode*>();
    if (1 == N) return vector<TreeNode*> (1, new TreeNode(0));
    else {
	vector<vector<TreeNode*>> map(N, vector<TreeNode*>());
	dfs(N-1, map);
	return map.at(N-1);
    }
}
