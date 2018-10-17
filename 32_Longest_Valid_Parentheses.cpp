#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        string tmp;
        vector<int> non_match_idice;
        int ret = 0, top = -1;
        for(int i = 0; i < s.length(); ++i) {
            if(s.at(i) == ')' && !tmp.empty() && tmp.back() == '(') {
                tmp.pop_back();
                top = non_match_idice.back();
                non_match_idice.pop_back();
                ret = max(ret, i - top);
            }
            else {
                tmp.push_back(s.at(i));
                non_match_idice.push_back(top);
                top = i;
            }
                
        }
        return ret;
    }
};

int main() {

    return 0;
}