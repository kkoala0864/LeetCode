#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
 //   vector<vector<int>> stations = {{47,220},{65,1},{98,113},{126,196},{186,218},{320,205},{686,317},{707,325},{754,104},{781,105}};
    vector<vector<int>> stations = {{50,50}};
    Solution* test = new Solution();
    cout << test->minRefuelStopsDP(100, 50, stations) << endl;
    cout << test->minRefuelStopsPQ(100, 50, stations) << endl;

    return 0;
}

