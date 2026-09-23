class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int size = s2.size();
        int i = 0;
        sort(s1.begin(), s1.end());
        while(i+k<=size) {
            string s = s2.substr(i,k);
            sort(s.begin(), s.end());
            if(s == s1) {
                return true;
            }
            i++;
        }
        return false;
    }
};
