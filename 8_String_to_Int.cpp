#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        auto start = find_if(str.begin(), str.end(), [](char c){return c != ' ';});
        if(start < str.end() && !isdigit(*start) && *start != '-' && *start != '+') return 0;
        auto end = find_if_not(start+1, str.end(), [](char c){return isdigit(c);});
        if(start >= end) return 0;
        string res = string(start, end);
        long long ret = 0;
        bool is_neg = res[0] == '-';
        for(auto iter = res.begin(); iter != res.end(); ++iter) {
            if(*iter == '-' || *iter == '+') continue;
            ret *= 10;
            ret += *iter - '0';
            if(!is_neg && ret > INT_MAX) return INT_MAX;
            else if(is_neg && ret*(-1) < INT_MIN) return INT_MIN;
        }
        return is_neg ? -1 * ret : ret;
    }
};
int main() {
    string str;
    cin >> str;
    cout << Solution().myAtoi(str);
    return 0;
}