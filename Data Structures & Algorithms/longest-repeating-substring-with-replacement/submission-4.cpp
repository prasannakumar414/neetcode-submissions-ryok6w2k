class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> firstIndex;
        unordered_map<char,int> lastIndex;
        unordered_map<char,int> oldestIndex;
        unordered_map<char,int> kMap;
        int size = s.size();
        int maxLength = 0;
        for(int i =0;i<size;i++) {
            char c = s[i];
            if(!oldestIndex.contains(c)) {
                oldestIndex[c] = i;
                firstIndex[c] = i;
                lastIndex[c] = i;
                kMap[c] = k;
                continue;
            }
            int currDist = i - lastIndex[c] - 1;
            int availableDist = kMap[c];
            if(currDist <= 0) {
                lastIndex[c] = i;
                continue;
            }
            if(currDist > availableDist) {
                if(currDist > k) {
                    int cLength = lastIndex[c] 
                    - oldestIndex[c] + 1 
                    + kMap[c];
                    if(cLength > maxLength) {
                        maxLength = cLength;
                    }
                    oldestIndex[c] = i;
                    firstIndex[c] = i;
                    lastIndex[c] = i;
                    kMap[c] = k;
                    continue;
                }
                int cLength = lastIndex[c] 
                - oldestIndex[c] + 1 
                + availableDist;
                if(cLength > maxLength) {
                    maxLength = cLength;
                }
                oldestIndex[c] = firstIndex[c];
                firstIndex[c] = i;
                lastIndex[c] = i;
                kMap[c] = k - currDist;
                continue;
            }
            firstIndex[c] = i;
            lastIndex[c] = i;
            kMap[c] = availableDist - currDist;
        }
        for(const auto& [key,value] : oldestIndex) {
            int cLength = lastIndex[key] - value + 1;
            cLength += min(kMap[key], (size - lastIndex[key] -1) + value);
            if (cLength > maxLength) {
                maxLength = cLength;
            }
        }
        return maxLength;
    }
};
