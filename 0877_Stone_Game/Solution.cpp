#include <Solution.h>
#include <iostream>
bool recursive(const vector<int>& piles, int round, int fIdx, int tIdx, int AlexCnt, int LeeCnt) {
    if (fIdx == tIdx) return AlexCnt > LeeCnt;

    if (round & 1) {
	return recursive(piles, round + 1, fIdx + 1, tIdx, AlexCnt, LeeCnt + piles.at(fIdx)) ||
	       recursive(piles, round + 1, fIdx, tIdx - 1, AlexCnt, LeeCnt + piles.at(tIdx));
    } else {
	return recursive(piles, round + 1, fIdx + 1, tIdx, AlexCnt + piles.at(fIdx), LeeCnt) ||
	       recursive(piles, round + 1, fIdx, tIdx - 1, AlexCnt + piles.at(tIdx), LeeCnt);
    }
}

bool Solution::stoneGame(vector<int>& piles) {
    if (piles.empty()) return false;
    int round(0);
    int fIdx(0);
    int tIdx(piles.size() - 1);
    int LeeCnt(0);
    int AlexCnt(0);
    while (fIdx != tIdx) {
	if (round & 1) {
	    if (piles.at(fIdx) < piles.at(tIdx)) {
		LeeCnt += piles.at(fIdx);
		++fIdx;
	    } else {
		LeeCnt = piles.at(tIdx);
		--tIdx;
	    }
	} else {
	    if (piles.at(fIdx) > piles.at(tIdx)) {
		AlexCnt += piles.at(fIdx);
		++fIdx;
	    } else {
		AlexCnt += piles.at(tIdx);
		--tIdx;
	    }
	}
    }
    return AlexCnt > LeeCnt;
}
