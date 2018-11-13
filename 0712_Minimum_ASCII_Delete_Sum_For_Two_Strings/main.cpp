#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    //string s1 = "gqirsclhrchxsqgmpfdeploxfixowfqqubuvsupkejabcrfqgcnsauunllsfskclenkxmdyraerhfmmiwryeyqoldgxctuvsjarjvfelsglvlbnozmejncnlaqpxmbrgwayfzczvatel";
    //string s2 = "kgievqcxvrgeyklbcidngseersbiubgdwzlraagerenyfavkdcriinaugodaoacfiasmhhoxxsnqcyfriknrjfwyfglplvodefdlbmykfgpdpzjndlrskzctfkfkwcjbibuglrjvdyfhnsgwuunpzoakyejkxczznfljimkkanlsyuhvwjitrdvktrvufgyllgjpjixotsgwjkzbdqhvzyappucwvberchznrzdqjwpvyckwbfnlulscxynfbqqkhgxxkdzawjtlncqqswfwwbvywdchnxtblboobjzkurpjutdbwaxlxkxuiaxiddntniuuvghprslmpctnokubadbbxhuezbesvgvptqbnfjpmxopjdrajectbpkszvzzjivzhlesfnzaetgvxcnrhuglvoncgsyoyucjnuedgcfdrnkhxfyhujxzvxieeevwqn";
    string s1 = "delete";
    string s2 = "leet";
    cout << test->minimumDeleteSum(s1, s2) << endl;
    cout << test->minimumDeleteSumII(s1, s2) << endl;
    cout << test->minimumDeleteSumIII(s1, s2) << endl;
    return 0;
}

