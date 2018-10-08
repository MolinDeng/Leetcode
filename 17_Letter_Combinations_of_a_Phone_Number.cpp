#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void DFS(vector<string>& ret, map<int, string>& M, string& digits, int idx) {
        static string tmp;
        if(idx == digits.length()) {
            ret.push_back(tmp);
            return;
        } 
        for(auto c : M[digits[idx]]) {
            tmp.push_back(c);
            DFS(ret, M, digits, idx + 1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        map<int, string> M = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ret;
        DFS(ret, M, digits, 0);
        return ret;
    }
};

int main() {
    vector<string> ret = Solution().letterCombinations("23");
    for(auto s : ret) cout << s << endl;
    return 0;
}