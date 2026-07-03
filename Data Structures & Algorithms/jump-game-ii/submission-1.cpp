class Solution {
public:
    int jump(vector<int>& nums) {
        unordered_map<int,int> memo;
        return minJumpFun(0, nums, memo);
    }
    int minJumpFun(int index,vector<int>& nums,unordered_map<int,int>& memo) {
        int length = nums.size();
        if(memo.contains(index)) {
            return memo[index];
        }
        if(index>=length) {
            memo[index]=2000;
            return memo[index];
        }
        if(index == length-1) {
            memo[index] = 0;
            return 0;
        }
        int minJump = 2000;
        for(int i=index+nums[index];i>index;i--){
            int currJump = 1 + minJumpFun(i,nums,memo);
            if(currJump < minJump) {
                minJump = currJump;
            }
        }
        memo[index] = minJump;
        return minJump;
    }
};
