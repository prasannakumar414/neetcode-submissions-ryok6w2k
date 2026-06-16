class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int l = 0;
        int r = size - 1;
        int maxArea = 0;
        while(l < r) {
            int len = r - l;
            int b_index = heights[l] > heights[r] ? r-- : l++;
            int area = len * heights[b_index];
            if (area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};
