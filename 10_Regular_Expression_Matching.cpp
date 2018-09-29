#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

class Solution1 {
public:
    bool isMatch(string s, string p) {
        regex r(p);
        return regex_match(s, r);
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int plen = p.length(), slen = s.length();
        vector<vector<bool> > dp(plen + 1, vector<bool>(slen + 1, false));
        dp[0][0] = true;
        if(!s.empty()) dp[1][1] = p[0] == '.' || p[0] == s[0];
        for(int u = 2; u <= plen; ++u) {
            dp[u][0] = (p[u-1] == '*' && dp[u-2][0]);
            for(int i = 1; i <= slen; ++i) 
                dp[u][i] = 
                    ((p[u-1] == '.' || p[u-1] == s[i-1]) && dp[u-1][i-1]) ||
                    (p[u-1] == '*' && (dp[u-2][i] || 
                                      (dp[u][i-1] && (p[u-2] == '.' || p[u-2] == s[i-1]))));
        }
        return dp[plen][slen];
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    cout << boolalpha << Solution1().isMatch(s, p) << endl;
    cout << boolalpha << Solution2().isMatch(s, p) << endl;
    return 0;
}