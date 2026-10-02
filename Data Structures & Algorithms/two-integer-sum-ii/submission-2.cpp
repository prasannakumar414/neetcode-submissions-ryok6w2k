class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> result;
        while(right > left) {
            int sum = numbers[left] + numbers[right];
            if(sum == target) {
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            if(sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};
