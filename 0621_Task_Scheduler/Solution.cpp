#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const int& lhs, const int& rhs) {
	return lhs < rhs;
    }
};

int Solution::leastInterval(vector<char>& tasks, int n) {
    priority_queue<int, vector<int>, cmp> maxHeap;
    vector<int> taskCnt(26,0);
    for (const auto& idx : tasks)
	++taskCnt.at(idx-'A');

    for (const auto& idx : taskCnt)
	if (idx > 0) maxHeap.emplace(idx);

    int retCnt(0);
    queue<int> que;
    while (!maxHeap.empty()) {
	int Cnt(0);
	while (!maxHeap.empty() && Cnt++ < (n+1)) {
	    int curVal = maxHeap.top() - 1;
	    maxHeap.pop();
	    if (curVal > 0)
		que.emplace(curVal);
	}
	if (que.empty() && maxHeap.empty())
	    retCnt += Cnt;
	else
	    retCnt += n+1;
	while (!que.empty()) {
	    maxHeap.emplace(que.front());
	    que.pop();
	}
    }
    return retCnt;
}


int Solution::leastInterval2(vector<char>& tasks, int n) {
    vector<int> cnt(26, 0);
    for (char task : tasks)
	++cnt[task - 'A'];

    sort(cnt.begin(), cnt.end());

    int i = 25, mx = cnt[25], len = tasks.size();
    int count = 0;
    while (i >= 0 && cnt[i] == mx) {
	--i; ++count;
    }
    return max(len, (mx - 1) * (n + 1) + count);
}

