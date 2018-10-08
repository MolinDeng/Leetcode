class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        if(s.length() % 2 != 0) return false;
        map<int, char> M = {{']', '['}, {')', '('}, {'}', '{'}};
        string Stack;
        for(auto c : s) {
            if(c == '[' || c == '{' || c == '(') Stack.push_back(c);
            else if(Stack.empty()) return false;
            else if(M[c] == Stack.back()) Stack.pop_back();
        }
        return Stack.empty();
    }
};