class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cItems;
        helper(result, nums, cItems, nums.size());
        return result;
    }

    void helper(vector<vector<int>>& result, vector<int> nums, vector<int> currItems, int targetSize) {
        if(currItems.size() == targetSize) {
            result.push_back(currItems);
            return;
        }
        for(int i = 0;i<nums.size();i++) {
            vector<int> cNums = nums;
            cNums.erase(cNums.begin() + i);
            vector<int> cItems = currItems;
            cItems.push_back(nums[i]);
            helper(result, cNums, cItems, targetSize);
        }
    }
};
