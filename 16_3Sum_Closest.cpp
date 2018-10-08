#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long res = INT_MAX, sum;
        sort(nums.begin(), nums.end());
        sum = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            if(i > 0 && a == nums[i-1]) continue;
            for(int left = i + 1, right = nums.size()-1; left < right; sum < target ? ++left: --right) {
                int b = nums[left], c = nums[right];
                sum = a + b + c;
                if(sum == target) return sum;
                if(abs(sum - target) < abs(res - target)) 
                    res = sum;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10};
    cout << Solution().threeSumClosest(nums, -52);
    return 0;
}