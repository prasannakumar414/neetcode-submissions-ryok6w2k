class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        set<vector<int>> result;
        for (int i = 0;i<size;i++) {
            int currVal = nums[i];
            if (i > 0) {
                if(currVal == nums[i-1]) {
                    continue;
                }
            }
            int l = i+1;
            int r = size-1;
            while(l<r) {
                int sum = nums[l] + nums[r];
                if(sum + currVal == 0) {
                    vector<int> v = {currVal, nums[l], nums[r]};
                    result.insert(v);
                    r--;
                }
                if (sum + currVal > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        vector<vector<int>> rv(result.begin(), result.end());
        return rv;
    }
};
