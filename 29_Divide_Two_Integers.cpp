#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1)) 
            return INT_MAX;
        int sign = (dividend > 0 ^ divisor > 0);
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int ret = 0;
        while(dvd >= dvs) {
            long long tmp = dvs, quo = 1;
            while(dvd >= (tmp << 1)) {
                tmp <<= 1;
                quo <<= 1;
            }
            dvd -= tmp;
            ret += quo;
        }
        return sign ? -ret : ret;
    }
};
int main() {
    cout << Solution().divide(13, 3);
    return 0;
}