class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        map<char, int> Map;
        int res = 0;
        for(int i = 0, j = 0; i < s.length() && j < s.length(); j++) {
            if(Map.find(s[j]) != Map.end()) {
                i = max(i, Map[s[j]] + 1);
            }
            Map[s[j]] = j;
            res = max(res, j-i+1);
        }
        return res;
    }
};

// 通过数组实现map也可以
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        vector<int> Map(256, 0);
        int res = 0;
        for(int i = 0, j = 0; i < s.length() && j < s.length(); j++) {
            i = max(i, Map[toascii(s[j])]);
            Map[toascii(s[j])] = j + 1;
            res = max(res, j-i+1);
        }
        return res;
    }
};