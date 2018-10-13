#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int i = 0;
        for(int j = 1; j < nums.size(); ++j) {
            if(nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main() {
    vector<int> nums = {0, 0, 1};
    Solution().removeDuplicates(nums);
    for(auto i : nums) cout << i << " ";
    return 0;
}