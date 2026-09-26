class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int max = 0;
        int maxIndex = -10001;
        vector<int> result = {};
        while(right < nums.size()) {
            if(nums[right]>max) {
                max = nums[right];
                maxIndex = right;
            }
            if(right >= k-1) {
                if(maxIndex < left) {
                    max = nums[left];
                    for(int i = left;i<=right;i++) {
                        if(nums[i]>max) {
                            max = nums[i];
                            maxIndex = i;
                        }
                    }
                }
                result.push_back(max);
                left++;
            }
            right++;
        }
        return result;
    }
};
