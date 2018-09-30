class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_area = 0;
        while(i < j) {
            int h = min(height[i], height[j]);
            max_area = max(max_area, h * (j - i));
            while(height[i] <= h && i < j) ++i;
            while(height[j] <= h && i < j) --j;
        }
        return max_area;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_area = 0;
        while(i < j) {
            int h = min(height[i], height[j]);
            max_area = max(max_area, h * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return max_area;
    }
};