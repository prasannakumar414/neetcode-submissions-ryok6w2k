class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> sMap;
        int start = 0;
        int currSize = 0;
        int maxSize = 0;
        for(int i = 0;i<s.size();i++) {
            if(sMap.contains(s[i]) && sMap[s[i]]>=start) {
                if(currSize > maxSize) {
                    maxSize = currSize;
                }
                start = sMap[s[i]]+1;
                currSize = i - sMap[s[i]]-1;
            }
            currSize++;
            sMap[s[i]] = i;
        }
        if(currSize > maxSize) {
            maxSize = currSize;
        }
        return maxSize;
    }
};
