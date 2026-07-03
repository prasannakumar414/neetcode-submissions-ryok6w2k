class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo;
        int t1 = text1.length();
        int t2 = text2.length();
        for(int i = 0;i<t1;i++) {
            vector<int> v;
            for(int j=0;j<t2;j++) {
                v.push_back(-1);
            }
            memo.push_back(v);
        }
        return lcs(text1,text2,0,0,memo);
    }

    int lcs(string& text1, string& text2,int ind1, int ind2,vector<vector<int>>& memo) {
        if (ind1 >= text1.length() || ind1<0) {
            return 0;
        }
        if (ind2 >= text2.length() || ind2<0) {
            return 0;
        }
        if (memo[ind1][ind2] != -1) {
            return memo[ind1][ind2];
        }
        // match case
        if(text1[ind1] == text2[ind2]) {
            memo[ind1][ind2] = max(
            1+lcs(text1,text2,ind1+1,ind2+1,memo),
            max(lcs(text1,text2,ind1+1,ind2,memo),
            lcs(text1,text2,ind1,ind2+1,memo))
            );
        } else {
            memo[ind1][ind2] = max(
                lcs(text1,text2,ind1+1,ind2+1,memo),
            max(lcs(text1,text2,ind1+1,ind2,memo),
            lcs(text1,text2,ind1,ind2+1,memo))
            );
        }
        return memo[ind1][ind2];
    }
};
