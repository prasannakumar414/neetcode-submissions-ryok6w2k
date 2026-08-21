class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currNums;
        sort(nums.begin(), nums.end());
        helper(result, nums, currNums, 0);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& nums, vector<int>& currNums, int curr) {
        result.push_back(currNums);
        for(int i = curr;i<nums.size();i++) {
            if(i>curr && nums[i]==nums[i-1]) {
                continue;
            }
            // vector<int> cNums = nums;
            // cNums.erase(cNums.begin() + i);
            currNums.push_back(nums[i]);
            helper(result, nums, currNums, i+1);
            currNums.pop_back();
        }
    }
};
