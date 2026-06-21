class Solution {
public:
// A solution using suffix and prefix max arrays
// time complexity is O(n) and space complexity of O(n)
    int trap(vector<int>& height) {
        int size = height.size();
        vector <int> prefix(size);
        vector<int> suffix(size);
        prefix[0] = height[0];
        for (int i = 1;i<size;i++) {
            prefix[i] = max(prefix[i-1], height[i]);
        }
        suffix[size-1] = height[size-1];
        for (int i = size-2;i>=0;i--) {
            suffix[i] = max(suffix[i+1], height[i]);
        }
        int resultArea = 0;
        for(int i = 0;i<size;i++) {
            resultArea += min(prefix[i],suffix[i]) - height[i];
        }
        return resultArea;
    }
};
