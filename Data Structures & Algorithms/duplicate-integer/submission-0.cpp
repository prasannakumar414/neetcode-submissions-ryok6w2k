class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map<int,bool> memo;
       for(int i = 0;i<nums.size();i++) {
        if(memo.contains(nums[i])){
            return true;
        }
        memo[nums[i]] = true;
       }
       return false; 
    }
};