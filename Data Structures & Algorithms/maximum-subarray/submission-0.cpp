class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        int size = nums.size();
        for(int i = 0;i<size;i++) {
            if(nums[i]+currSum > maxSum) {
                maxSum = nums[i] + currSum;
                currSum = maxSum;
            } else {
                if (nums[i]+currSum < 0) {
                    currSum = 0;
                } else {
                    currSum = nums[i]+currSum;
                }
            }
        }
        return maxSum;
    }
};
