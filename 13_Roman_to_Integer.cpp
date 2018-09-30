class Solution {
public:
    int romanToInt(string s) {
        vector<int> Map(256, 0);
        Map['I'] = 1;Map['V'] = 5;Map['X'] = 10;Map['L'] = 50;
        Map['C'] = 100;Map['D'] = 500;Map['M'] = 1000;
        vector<int> values;
        for(auto c : s)
            values.push_back(Map[c]);
        int ret = 0, pre = 0;
        for(auto riter = values.rbegin(); riter != values.rend(); ++riter) {
            int v = *riter;
            if(v >= pre) {
                ret += v;
                pre = v;
            }
            else ret -= v;
        }
        return ret;
    }
};