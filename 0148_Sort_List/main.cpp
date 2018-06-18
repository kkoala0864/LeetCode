#include <Solution.h>
#include <iostream>
#include <vector>
using namespace std;
ListNode* Add(vector<int>& val) {
    ListNode* head = nullptr;
    ListNode* append = head;
    for (const auto& idx : val) {
	ListNode* node = new ListNode(idx);
	if (head == nullptr) {
	    head = node;
	    append = node;
	} else {
	    append->next = node;
	    append = node;
	}
    }
    return head;
}

int main(void) {
    vector<int> input = {4,19,14,5,-3,1,8,5,11,15};
    //vector<int> input = {5,11,15};
    //vector<int> input = {-84,142,41,-17,-71,170,186,183,-21,-76,76,10,29,81,112,-39,-6,-43,58,41,111,33,69,97,-38,82,-44,-7,99,135,42,150,149,-21,-30,164,153,92,180,-61,99,-81,147,109,34,98,14,178,105,5,43,46,40,-37,23,16,123,-53,34,192,-73,94,39,96,115,88,-31,-96,106,131,64,189,-91,-34,-56,-22,105,104,22,-31,-43,90,96,65,-85,184,85,90,118,152,-31,161,22,104,-85,160,120,-31,144,115};

    ListNode* first = Add(input);
    Solution* test = new Solution();
    ListNode* ret = test->sortList(first);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}

