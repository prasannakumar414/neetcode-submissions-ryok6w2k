class Solution {
public:
    string minWindow(string s, string t) {
        array<int,60> need = {0};
        int size = t.size();
        int required = size;
        for(int i = 0; i<size;i++) {
            need[t[i] - 'A']++;
        }
        int left = 0;
        int minLen = s.size() + 1;
        int minLeft = 0;
        for(int right = 0; right < s.size();right++) {
            int aVal = s[right]-'A';
            if(need[aVal] > 0) {
                required--;
            }
            need[aVal]--;
            while(required == 0) {
                if(right-left+1 < minLen) {
                    minLen = right-left+1;
                    minLeft = left;
                }
                need[s[left]-'A']++;
                if(need[s[left]-'A']>0) {
                    required++;
                }
                left++;
            }
        }
        if(minLen == s.size() + 1) {
            return "";
        }
        return s.substr(minLeft, minLen);
    }
};
