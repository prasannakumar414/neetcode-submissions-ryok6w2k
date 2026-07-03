class Solution {
public:
// Greedy solution
    int jump(vector<int>& nums) {
        int size = nums.size();
        int l = 0;
        int r = 0;
        int res = 0;
        while(r < size-1) {
            int longest = 0;
            for(int i = l;i<r+1;i++) {
                longest = max(i+nums[i], longest);
            }
            l = r;
            r = longest;
            res += 1;
        }
        return res;
    }
};
