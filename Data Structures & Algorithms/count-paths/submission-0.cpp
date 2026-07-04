class Solution {
public:
    int uniquePaths(int m, int n) {
        map<pair<int,int>,int> memo;
        return uniq(m,n,0,0,memo);
    }
    int uniq(int m,int n,int r,int c,map<pair<int,int>,int>& memo) {
        if(r == m-1 && c == n-1) {
            return 1;
        }
        if(r >= m || c >= n) {
            return -1;
        }
        if(memo.contains({r,c})) {
            return memo[{r,c}];
        }
        int v1 = uniq(m,n,r+1,c,memo);
        int v2 = uniq(m,n,r,c+1,memo);
        int ans = 0;
        if(v1>=0) {
            ans += v1;
        }
        if(v2>=0) {
            ans += v2;
        }
        memo[{r,c}]=ans;
        return ans;
    }
};
