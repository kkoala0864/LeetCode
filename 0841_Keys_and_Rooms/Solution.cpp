#include <Solution.h>
#include <iostream>

void visitRoom(const vector<vector<int>>& rooms, int roomNum,
	                    vector<bool>& lock, int& lockNum) {
    --lockNum;
    lock.at(roomNum) = false;
    for (const auto& keyNum : rooms.at(roomNum)) {
	if (lock.at(keyNum)) {
	    visitRoom(rooms, keyNum, lock, lockNum);
	}
    }
}

bool Solution::canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> lock(rooms.size(), true);
    int lockNum = rooms.size();
    visitRoom(rooms, 0, lock, lockNum);
    return lockNum <= 0;
}
