#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int tot_len;
    int len;
    vector<bool> visited;
    bool DFS(int idx,const string& s, vector<string>& words, int t) {
        if(t == tot_len) return true;
        for(int i = 0; i < words.size(); ++i) {
            if(!visited[i] && words[i] == s.substr(idx, len)) {
                visited[i] = true;
                return DFS(idx+len, s, words, t+len);
            } 
        }
        return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.empty()) return ret;
        len = words[0].length(), tot_len = len * words.size();
        if(s.length() < tot_len) return ret;
        visited.resize(tot_len, false);
        for(int i = 0; i <= s.length() - tot_len; ++i) {
            fill(visited.begin(), visited.end(), false);
            if(DFS(i, s, words, 0)) 
                ret.push_back(i);
        }
        return ret;
    }
};

class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.empty() || s.empty()) return ret;
        unordered_map<string, int> cnt;
        for(auto s : words) cnt[s]++;
        int wl = words[0].length(), len = wl * words.size();
        for(int i = 0, j; i < s.length() - len + 1; ++i) {
            unordered_map<string, int> tmp = cnt;
            for(j = 0; j < words.size(); ++j) {
                string w = s.substr(i+j*wl, wl);
                if(tmp.count(w) == 0 || --tmp[w] < 0) break;
            }
            if(j == words.size()) ret.push_back(i);
        }
        return ret;
    }
};
int main() {
    vector<string> w = {"word","good","best","word"};
    string s = "wordgoodgoodgoodbestword";
    vector<int> ret = Solution().findSubstring(s, w);
    for(auto i : ret) cout << i << endl;
    return 0;
}