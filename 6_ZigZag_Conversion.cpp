#include <iostream>
#include <string>
#include <vector>

using namespace std;
// T = O(N) S = O(N)
class Solution1 {
public:
    string convert(string s, int numRows) {
        if(s.length() <= numRows || numRows == 1) return s;
        vector<string> ZigZag(numRows, "");
        string res;
        for(int i = 0, j = 0, k = -1; i < s.length(); ++i, j += k) {
            if(j == 0 || j == numRows-1) k *= -1;
            ZigZag[j].push_back(s[i]);
        }
        for(int i = 0; i < numRows; ++i)
            res = res + ZigZag[i];
        return res;
    }
};
// S = O(1)
class Solution2 {
public:
    string convert(string s, int numRows) {
        string res;
        int cLen = 2*numRows - 2;
        int N = s.length();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j + i < N; j += cLen) {
                res += s[i + j];
                if(i != 0 && i != numRows - 1 && j + cLen - i < N)
                    res += s[j + cLen -i];// 位置j一个垂直位置，j+clen下一个垂直位置，j+clen-i得到第i行斜边位置
            }
        }
        return res;
    }
};

int main() {
    Solution1 s;
    cout << s.convert("AB", 1);
    return 0;
}