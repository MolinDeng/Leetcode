#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(needle.length() > haystack.length()) return -1;
        int len = needle.length();
        vector<int> shift(256, len+1);
        for(int i = 0; i < len; ++i) 
            shift[needle[i]]  = len - i;
        for(int i = 0, j = 0; i + len <= haystack.length(); i += shift[haystack[i+len]], j = 0) {
            while(j < len && haystack[i+j] == needle[j]) j++;
            if(j == len) 
                return i;
        }
        return -1;
    }
};

int main() {
    cout << Solution().strStr("hello", "ll");
    return 0;
}