class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anMap;
        for(int i=0;i<strs.size();i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            anMap[s].push_back(strs[i]);
        }
        for(const auto& pair:anMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};
