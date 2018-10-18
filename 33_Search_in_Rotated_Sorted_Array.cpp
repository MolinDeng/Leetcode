#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                if(nums[right] < target && nums[right] >= nums[mid])
                    right = mid - 1;
                else 
                    left = mid + 1;
            } 
            else {
                if(nums[left] > target && nums[left] <= nums[mid])
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        /*
        find the index of the smallest value using binary search.
        Loop will terminate since mid < right, and left or right will shrink by at least 1.
        Proof by contradiction that mid < right: if mid==right, then left==right and loop would have been terminated.
        */
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        int root_idx = left;
        // left==right is the index of the smallest value and also the number of places rotated.
        left = 0; right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            int realmid = (mid + root_idx) % nums.size();
            if(nums[realmid] == target) return realmid;
            else if(nums[realmid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3,1};
    int target;
    cin >> target;
    cout << Solution().search(nums, target);
    return 0;
}