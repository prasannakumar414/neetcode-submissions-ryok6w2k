class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> backward(size);
        vector<int> forward(size);
        forward[0] = nums[0];
        for(int i = 1;i<size;i++) {
            forward[i] = forward[i-1]*nums[i];
        }
        backward[size-1] = nums[size-1];
        for(int i = size-2;i>=0;i--) {
            backward[i] = backward[i+1]*nums[i];
        }
        vector<int> result;
        result.push_back(backward[1]);
        for(int i = 1;i<size-1;i++) {
            result.push_back(forward[i-1]*backward[i+1]);
        }
        result.push_back(forward[size-2]);
        return result;
    }
};
