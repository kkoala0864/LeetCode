#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> head, tail, *phead, *ptail;
	unordered_set<string> wordDict(wordList.begin(), wordList.end());
	if(wordDict.find(endWord)==wordDict.end())
		return 0;
	head.insert(beginWord);
	tail.insert(endWord);
	int dist = 2;
	while (!head.empty() && !tail.empty())
	{
		if (head.size() < tail.size()) {
			phead = &head;
			ptail = &tail;
		}
		else {
			phead = &tail;
			ptail = &head;
		}
		unordered_set<string> temp;
		for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
			string word = *itr;
			wordDict.erase(word);
			for (int p = 0; p < (int)word.length(); p++) {
				char letter = word[p];
				for (char v='a';v <= 'z';v++) {
					word[p] = v;
					if (ptail -> find(word) != ptail -> end())
						return dist;
					if (wordDict.find(word) != wordDict.end()) {
						temp.insert(word);
						wordDict.erase(word);
					}
				}
				word[p] = letter;
			}
		}
		dist++;
		swap(*phead, temp);
	}
	return 0;
}

