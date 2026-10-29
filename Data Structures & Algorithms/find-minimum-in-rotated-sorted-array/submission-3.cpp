class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int size = nums.size();
        int right = size - 1;
        while(right > left) {
            int mid = (right + left)/2;
            int midVal = nums[mid];
            int leftVal = nums[left];
            int rightVal = nums[right];
            if(midVal > rightVal) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
