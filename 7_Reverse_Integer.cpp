class Solution1 {
public:
    int reverse(int x) {
        if(abs(x) < 10) return x;
        bool isN = false;
        if(x < 0) isN = true;
        x = abs(x);
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++)
            if(s[i] != '0') {
                long long res = stoll((isN ? "-" : "") + s.substr(i));
                if(res > INT_MAX || res < INT_MIN) return 0;
                else return res;
            }
    }
};
// beats 97.93% 12ms
class Solution2 {
public:
    int reverse(int x) {
        if(abs(x) < 10) return x;
        bool isN = false;
        if(x < 0) isN = true;
        x = abs(x);
        long long ret = 0;
        while(x) {
            ret *= 10;
            ret += x % 10;
            if(ret > INT_MAX || ret < INT_MIN) return 0;
            x /= 10;
        }
        return isN ? -1*ret : ret;
    }
};