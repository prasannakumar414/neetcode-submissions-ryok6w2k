class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ind = 0;
        int cols = matrix[0].size();
        int rows = matrix.size();
        while(ind < rows) {
            if(target >= matrix[ind][0] 
                && target <= matrix[ind][cols-1]) {
                    break;
            }
            ind++;
        }
        if(ind == rows) {
            return false;
        }
        return findBST(matrix[ind], 0, cols, target);
    }

    bool findBST(vector<int>& arr,int start,int last,int target) {
        int left = start;
        int right = last-1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return false;
    }
};
