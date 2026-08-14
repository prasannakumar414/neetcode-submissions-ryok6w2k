class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back({});
        result = getSubset(result, nums);
        return result;
    }

    vector<vector<int>> getSubset(vector<vector<int>> &result,vector<int>& nums) {
        int size = result.size();
        if(nums.size()==0) {
            return result;
        }
        for(int i =0;i<size;i++) {
            vector<int> arr = result[i];
            arr.push_back(nums[0]);
            result.push_back(arr);
        }
        vector<int> sub(nums.begin()+1, nums.end());
        return getSubset(result,sub);
    }
};
