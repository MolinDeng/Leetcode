class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        string head = strs.front(); 
        string tail = strs.back();
        int len = min(head.length(), tail.length()), i = 0;
        for(; i < len && head[i] == tail[i]; ++i);
        return head.substr(0, i);
    }
};