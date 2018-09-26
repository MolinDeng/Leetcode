#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// wrong for input "aacdefcaa", output "aac"
class Solution_error {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        string rs(s.rbegin(), s.rend());
        int len = s.length();
        int idx, maxL = 0;
        vector<vector<int> > dp(len+1, vector<int>(len+1, 0));
        for(int i = 1; i <= len; i++) {
            for(int j = 1; j <= len; j++) {
                if(s[i-1] == rs[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] >= maxL) {
                    maxL = dp[i][j];
                    idx = j;
                }
            }
        }
        return rs.substr(idx - maxL, maxL);
    }
};

class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s == "") return s;
        string res = s.substr(0, 1);
        int len = s.length(), maxL = 1;
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for(int i = 0; i < len; i++) {
            dp[i][i] = true;
            if(i+1 < len && s[i] == s[i+1]) {
                dp[i+1][i] = dp[i][i+1] = true;
            }
        }
        for(int L = 2; L <= len; ++L) {
            for(int i = 0; i + L - 1 < len; i++) {
                int j = i + L - 1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if(L > maxL) {
                        res = s.substr(i, L);
                        maxL = L;
                    }
                }
            } 
        }
        return res;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        if(s == "") return s;
        string res = "";
        int len = s.length();
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for(int i = len - 1; i >= 0; --i) {
            for(int j = i; j < len; ++j) {
                if(s[i] == s[j] && (j - i < 3 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if(j - i + 1 > res.length()) 
                        res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    string s = "babad";
    cout << s.substr(0, 10) << "~";
    return 0;
}