#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::carFleet(int target, vector<int>& position, vector<int>& speed) {
    if (position.size() < 2) return position.size();
    vector<pair<int, double>> ArriveTime;
    for (int i = 0 ; i < position.size() ; ++i) {
	ArriveTime.emplace_back(position.at(i), ((double)target - (double)position.at(i)) / (double)speed.at(i));
    }

    sort(ArriveTime.begin(), ArriveTime.end(),
	    [] (const pair<int, double>& a,
		const pair<int, double>& b)->bool {
		    return a.first > b.first;
		});

    pair<int, double> cur = ArriveTime.at(0);
    int cnt(1);
    for (int i = 1 ; i < ArriveTime.size() ; ++i) {
	if (cur.second < ArriveTime.at(i).second) {
	    cur = move(ArriveTime.at(i));
	    ++cnt;
	}
    }
    return cnt;
}
