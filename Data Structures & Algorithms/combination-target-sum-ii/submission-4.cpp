class Solution {
public:
    void sortVector(vector<int>& candidates) {
        sort(candidates.begin(), candidates.end());
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currC;
        sortVector(candidates);
        helper(result, candidates, currC, target, 0);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& candidates, vector<int>& currCandidates, int target, int curr) {
        if (target == 0) {
            result.push_back(currCandidates);
            return;
        }
        for(int i=curr;i<candidates.size(); i++) {
            if (i > curr && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(candidates[i] > target) {
                break;
            }
            currCandidates.push_back(candidates[i]);
            helper(result, candidates, currCandidates, target-candidates[i], i+1);
            currCandidates.pop_back();
        }
    }
};
