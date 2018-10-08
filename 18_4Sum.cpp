#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// beats 77.94%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        if(nums.size() < 4) return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++i) {
            int a = nums[i];
            if(i > 0 && nums[i-1] == a) continue;
            for(int j = i + 1; j < nums.size() - 2; ++j) {
                int b = nums[j];
                if(j > i + 1 && nums[j-1] == b) continue;
                for(int m = j + 1, n = nums.size() - 1; m < n; ) {
                    int c = nums[m], d = nums[n];
                    int sum = a + b + c + d;
                    if(sum == target) {
                        ret.push_back({a, b, c, d});
                        while(m < n && nums[++m] == c);
                        while(m < n && nums[--n] == d);
                    }
                    else if(sum < target) ++m;
                    else --n;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret = Solution().fourSum(nums , 0);
    for(auto v : ret) {
        for(auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}