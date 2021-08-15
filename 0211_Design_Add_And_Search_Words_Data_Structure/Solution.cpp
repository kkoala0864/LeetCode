#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

Solution::Solution() {
	if (root) return;
	root = new Node();
}

void Solution::addWord(string word) {
	Node *node = root;
	for (auto& iter : word) {
		if (!node->Next[iter-'a']) {
			node->Next[iter-'a'] = new Node();
		}
		node = node->Next[iter-'a'];
	}
	node->Word = true;
}

bool searchRecur(string word, int index, Node *node) {
	if (!node) return false;
	if (index == word.length()) {
		return node->Word;
	}
	if (word[index] == '.') {
		for (auto iter : node->Next) {
			if (searchRecur(word, index+1 , iter)) return true;
		}
		return false;
	}
	return searchRecur(word, index+1, node->Next[word[index] - 'a']);
}

bool Solution::search(string word) {
	Node* node = root;
	return searchRecur(word, 0, root);
}

