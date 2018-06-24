#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<Interval> input;
    input.emplace_back(9, 10);
    input.emplace_back(4, 9);
    input.emplace_back(4, 17);
    Solution* test = new Solution();
    cout << test->minMeetingRooms(input) << endl;

    return 0;
}

