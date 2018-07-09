#include <Solution.h>
#include <iostream>
using namespace std;
int main(void) {
    //vector<pair<string, string>> input = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<pair<string, string>> input = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution* test = new Solution();
    vector<string> ret = test->findItinerary(input);
    for (const auto& idx : ret) {
	cout << idx << " ";
    }
    cout << endl;

    return 0;
}

