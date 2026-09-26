class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        int left = size - 2;
        int max = size - 1;
        vector<int> result;
        result.push_back(0);
        while(left >= 0) {
            if(temperatures[left] >= temperatures[max]) {
                result.push_back(0);
                max = left;
            } else {
                int r = max;
                int maxR = r;
                while(r > left) {
                    if(temperatures[left] < temperatures[r]) {
                        maxR = r;
                    }
                    r--;
                }
                result.push_back(maxR - left);
            }
            left--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
