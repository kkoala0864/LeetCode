#include <Solution.h>
#include <iostream>

using namespace std;
int main(void) {
    vector<pair<string, string>> pairs = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}};
    //vector<pair<string, string>> pairs = {{"great","good"},{"extraordinary","good"},{"well","good"},{"wonderful","good"},{"excellent","good"},{"fine","good"},{"nice","good"},{"any","one"},{"some","one"},{"unique","one"},{"the","one"},{"an","one"},{"single","one"},{"a","one"},{"truck","car"},{"wagon","car"},{"automobile","car"},{"auto","car"},{"vehicle","car"},{"entertain","have"},{"drink","have"},{"eat","have"},{"take","have"},{"fruits","meal"},{"brunch","meal"},{"breakfast","meal"},{"food","meal"},{"dinner","meal"},{"super","meal"},{"lunch","meal"},{"possess","own"},{"keep","own"},{"have","own"},{"extremely","very"},{"actually","very"},{"really","very"},{"super","very"}};
    vector<string> word1 = {"great", "acting", "skills"};
    vector<string> word2 = {"fine", "drama", "talent"};
    //vector<string> word1 = {"an","extraordinary","meal"};
    //vector<string> word2 = {"one","good","dinner"};
    Solution* test = new Solution();
    cout << test->areSentencesSimilarTwo(word1, word2, pairs) << endl;

    return 0;
}

