class Solution { 
public:
// This solution has time complexity of O(n) and Space Complexity of O(1)
    int trap(vector<int>& height) {
        int size = height.size();
        int l = 0;
        int r = size - 1;
        int curr = l + 1;
        bool plus = true;
        int min = height[l];
        if (height[l] > height[r]) {
            min = height[r];
            curr = r - 1;
            plus = false;
        }
        int resultArea = 0;
        while (l != r) {
            resultArea += max(0, min - height[curr]);
            if(height[curr] >= min) {
                if(plus) {
                    l = curr;
                } else {
                    r = curr;
                }
                curr = l + 1;
                plus = true;
                min = height[l];
                if (height[l] > height[r]) {
                    min = height[r];
                    curr = r - 1;
                    plus = false;
                }
            } else {
                if (plus) {
                    curr++;
                } else {
                    curr--;
                }
            }
        }
        return resultArea;
    }
};
