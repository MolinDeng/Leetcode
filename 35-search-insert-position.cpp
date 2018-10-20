#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int a;
    cin >> a;
    cout << Solution().searchInsert(nums, a);
    return 0;
}