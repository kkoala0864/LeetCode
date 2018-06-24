#include <Solution.h>
#include <iostream>
#include <unordered_map>
using namespace std;

int Solution::fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int cnt(0);
    unordered_map<int, int> ab, cd;
    int size = A.size();
    for (int i = 0 ; i < size ; ++i) {
	for (int j = 0 ; j < size ; ++j) {
	    ++ab[A[i]+B[j]];
	}
    }

    auto end = ab.end();
    for (int i = 0 ; i < size ; ++i) {
	for (int j = 0 ; j < size ; ++j) {
	    auto it = ab.find(-(C[i]+D[j]));
	    if (it != end) cnt += it->second;
	}
    }
    return cnt;
}

