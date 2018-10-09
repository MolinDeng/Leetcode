#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    void DFS1(vector<string>& v, int lp, int rp, const int n) {
        static string tmp;
        if(lp + rp == 2*n) {
            v.push_back(tmp);
            return;
        }
        if(lp == n) {
            tmp.push_back(')');
            DFS1(v, lp, rp+1, n);
            tmp.pop_back();
        }
        else if(lp > rp) {
            tmp.push_back('(');
            DFS1(v, lp+1, rp, n);
            tmp.pop_back();
            tmp.push_back(')');
            DFS1(v, lp, rp+1, n);
            tmp.pop_back();
        }
        else if(lp == rp) {
            tmp.push_back('(');
            DFS1(v, lp+1, rp, n);
            tmp.pop_back();
        }
    }
    void DFS2(vector<string>& v, int lp, int rp, const int n) {
        static string tmp;
        if(lp + rp == 2*n) {
            v.push_back(tmp);
            return;
        }
        if(lp < n) {
            tmp.push_back('(');
            DFS2(v, lp+1, rp, n);
            tmp.pop_back();
        }
        if(lp > rp) {
            tmp.push_back(')');
            DFS2(v, lp, rp+1, n);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n != 0)
            DFS2(ret, 0, 0, n);
        return ret;
    }
};

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n == 0) ret.push_back("");
        else 
            for(int c = 0; c < n; ++c) 
                for(auto left : generateParenthesis(c)) 
                    for(auto right : generateParenthesis(n-c-1))
                        ret.push_back("(" + left + ")" + right);
        return ret;
    }
};
int main() {
    vector<string> ret = Solution2().generateParenthesis(3);
    for(auto s : ret) cout << s << endl;
    return 0;
}