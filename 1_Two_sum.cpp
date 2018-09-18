class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            auto pos = std::find(nums.begin()+1+i, nums.end(), target - nums[i]);
            if(pos != nums.end()) {
                res.push_back(i);
                res.push_back(pos - nums.begin());
                break;
            }
        }
        return res;
    }
};