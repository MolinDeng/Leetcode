#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1; i > 0; --i) {
            if(nums[i-1] < nums[i]) {
                sort(nums.begin()+i, nums.end());
                for(int j = i; j < nums.size(); ++j) {
                    if(nums[j] > nums[i-1]) {
                        swap(nums[i-1], nums[j]);  
                        return;
                    }
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main() {

    return 0;
}