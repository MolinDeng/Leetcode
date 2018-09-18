// O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size() + nums2.size();
        int N = (nums1.size() + nums2.size()) / 2 + 1, i = 0, j = 0;
        vector<int> S;
        while(S.size() != N && i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) 
                S.push_back(nums1[i++]);
            else
                S.push_back(nums2[j++]);
        }
        while(S.size() != N) {
            if(i < nums1.size()) S.push_back(nums1[i++]);
            if(j < nums2.size()) S.push_back(nums2[j++]);
        }
        return total_size % 2 == 1 ? (double)S.back() : (S[S.size()-1] + S[S.size()-2]) / 2.0;
    }
};