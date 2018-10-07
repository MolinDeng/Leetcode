class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; nums[i] <= 0; ++i) {
            int a = nums[i];
            if(i > 0 && a == nums[i-1]) continue;
            for(int left = i + 1, right = nums.size()-1; left < right; ) {
                int b = nums[left], c = nums[right];
                int sum = a + b + c;
                if(sum == 0) {
                    res.push_back(vector<int>({a, b, c}));
                    while(left < right && b == nums[++left]);
                    while(left < right && c == nums[--right]);
                }
                else if(sum > 0) right--;
                else left++;
            }
        }
        return res;
    }
};