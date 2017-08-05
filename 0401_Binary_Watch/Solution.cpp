#include <Solution.h>
#include <iostream>

using namespace std;

vector<string> Solution::readBinaryWatch(int num) {

	if ( 8 < num ) {
		vector<string> ret;
		return ret;
	}

	vector<vector<string> > ret;
	ret.resize(9);
	for (int hrIdx=0 ; hrIdx < 12; ++hrIdx) {
		int hrCnt = 0;
		int hrTmp = hrIdx;
		for (int idx=0 ; idx < 4 ; ++idx) {
			if (hrTmp & 0x1)
				++hrCnt;
			hrTmp = hrTmp >> 1;
		}
		for (int minIdx=0 ; minIdx < 60 ; ++minIdx) {
			int minCnt = 0;
			int minTmp = minIdx;
			for (int idx=0 ; idx < 6 ; ++idx) {
				if (minTmp & 0x1)
					++minCnt;
				minTmp = minTmp >> 1;
			}
			string retStr;
			retStr.append(to_string(hrIdx));
			retStr.append(":");
			if (minIdx < 10)
				retStr.append("0");
			retStr.append(to_string(minIdx));
			ret[hrCnt + minCnt].push_back(retStr);
		}
	}
	return ret[num];
}

