class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJumpIndex(0,nums);
    }
    bool canJumpIndex(int index, vector<int>& nums) {
        int length = nums.size();
        if (index == length-1) {
            return true;
        }
        if(index >= length) {
            return false;
        }
        for(int i = nums[index];i>0;i--) {
            if(canJumpIndex(index+i, nums)) {
                return true;
            }
        }
        return false;
    }
};
