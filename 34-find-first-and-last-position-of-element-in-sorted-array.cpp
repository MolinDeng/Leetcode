#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1, -1};
        if(nums.empty()) return ret;
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if(left >= 0 && left < nums.size() && nums[left] == target) ret[0] = left;
        if(ret[0] != -1) {
            left = 0; right = nums.size();
            while(left < right) {
                int mid = (left + right) / 2;
                if(nums[mid] <= target) left = mid + 1;
                else right = mid;
            }
            ret[1] = --left;
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target;
    cin >> target;
    vector<int> ret = Solution().searchRange(nums, target);
    cout << ret[0] << " " << ret[1];
    return 0;
}