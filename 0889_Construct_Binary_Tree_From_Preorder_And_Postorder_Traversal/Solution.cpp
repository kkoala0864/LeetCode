#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
TreeNode* construct(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
    if (preStart == preEnd) {
	return new TreeNode(pre.at(preStart));
    } else if (preStart > preEnd) {
	return NULL;
    }

    TreeNode* retNode = new TreeNode(pre.at(preStart));

    if (pre.at(preStart + 1) == post.at(postEnd - 1)) {
	retNode->left = construct(pre, preStart + 1, preEnd, post, postStart, postEnd - 1);
    } else {
	int LeftPreStart = preStart + 1;
	int RightPostEnd = postEnd - 1;
	int i = LeftPreStart;
	while (pre.at(i) != post.at(RightPostEnd) && i <= preEnd) ++i;
	int LeftPreEnd = i - 1;
	int RightPreStart = LeftPreEnd + 1;

	i = RightPostEnd;
	while (post.at(i) != pre.at(LeftPreStart) && i >= postStart) --i;
	int RightPostStart = i + 1;
	int LeftPostEnd = RightPostStart - 1;

	retNode->left = construct(pre, LeftPreStart, LeftPreEnd, post, postStart, LeftPostEnd);
	retNode->right = construct(pre, RightPreStart, preEnd, post, RightPostStart, RightPostEnd);
    }
    return retNode;
}

TreeNode* Solution::constructFromPrePost(vector<int>& pre, vector<int>& post) {
    if (pre.empty()) return NULL;
    int size = pre.size();
    return construct(pre, 0, size - 1, post, 0, size - 1);
}
