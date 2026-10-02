class Solution {
public:
    int bs(vector<int>& numbers, int target, int start, int end) {
        while(start <= end) {
            int mid = (start + end)/2;
            if(numbers[mid] == target) {
                return mid;
            } else if (numbers[mid] > target) {
                end = mid-1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
      for(int i = 0;i<numbers.size();i++) {
        int val = bs(numbers, target - numbers[i], i+1, numbers.size() - 1);
        if(val != -1) {
            result.push_back(i + 1);
            result.push_back(val + 1);
            break;
        }
      }
      return result;
    }
};
