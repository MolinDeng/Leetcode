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

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> value2idx;
        for(int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];
            if(value2idx.count(k)) 
                return {value2idx[k], i};
            value2idx[nums[i]] = i;
        }
        return res;
    }
};