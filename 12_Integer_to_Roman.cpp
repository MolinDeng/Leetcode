class Solution1 {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

class Solution2 {
public:
    string intToRoman(int num) {
        string ret, s;
        for(int expo = 1; num > 0; num /= 10, expo *= 10) {
            int r = num % 10;
            if(r == 0) continue;
            else if(r <= 3) {
                switch(expo) {
                    case 1: s = "I"; break;
                    case 10: s = "X"; break;
                    case 100: s = "C"; break;
                    case 1000: s = "M"; break;
                }
                for(int i = 0; i < r; i++) ret = s + ret;
            }
            else if(r == 5) {
                switch(expo) {
                    case 1: s = "V"; break;
                    case 10: s = "L"; break;
                    case 100: s = "D"; break;
                }
                ret = s + ret;
            }
            else if(r == 4) {
                switch(expo) {
                    case 1: s = "IV"; break;
                    case 10: s = "XL"; break;
                    case 100: s = "CD"; break;
                }
                ret = s + ret;
            }
            else if(r <= 8) {
                switch(expo) {
                    case 1: s = "VI"; break;
                    case 10: s = "LX"; break;
                    case 100: s = "DC"; break;
                }
                for(int i = 0; i < r - 6; ++i) s.push_back(s.back());
                ret = s + ret;
            }
            else if(r == 9) {
                switch(expo) {
                    case 1: s = "IX"; break;
                    case 10: s = "XC"; break;
                    case 100: s = "CM"; break;
                }
                ret = s + ret;
            }
        }
        cout << ret;
        return ret;
    }
};