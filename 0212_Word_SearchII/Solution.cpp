#include <Solution.h>
#include <iostream>
using namespace std;

void insertWord(TrieNode* root, const string& word) {
    for (const auto& c : word) {
	if (nullptr == root->children.at(c-'a')) {
	    root->children.at(c-'a') = new TrieNode();
	}
	root = root->children.at(c-'a');
    }
    root->word = word;
}

TrieNode* BuildTrie(const vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const auto& word : words) {
	insertWord(root, word);
    }
    return root;
}

void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& ret) {
    if (root == nullptr) return;
    if (!root->word.empty()) {
	ret.emplace_back(root->word);
	root->word.clear();
    }

    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    char curChar = board.at(i).at(j);
    board.at(i).at(j) = '#';
    for (const auto& direction : directions) {
	int x = i + direction.first;
	int y = j + direction.second;
	if (x >= 0 && x < board.size() && y >= 0 && y < board.at(0).size() && board.at(x).at(y) != '#') {
	    dfs(board, x, y, root->children.at(board.at(x).at(y)-'a'), ret);
	}
    }
    board.at(i).at(j) = curChar;
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    if (words.empty()) return ret;
    TrieNode* root = BuildTrie(words);
    for (int i = 0 ; i < board.size() ; ++i) {
	for (int j = 0 ; j < board.at(0).size() ; ++j) {
	    dfs(board, i, j, root->children.at(board.at(i).at(j) - 'a'), ret);
	}
    }
    return ret;
}
