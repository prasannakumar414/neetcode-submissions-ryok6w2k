class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // memoization
        int rows = coins.size();
        int cols = amount+1;
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        return coinChange(amount, 0, coins, memo);
    }
    int coinChange(int amount,int index, vector<int>& coins, vector<vector<int>>& memo) {
        if(index > coins.size()-1) {
            return 0;
        }
        // base case if amount is already 0 no need for coins right
        if(amount == 0) {
            return 1;
        }
        if(memo[index][amount] != -1) {
            return memo[index][amount];
        }
        // if the coin we are cannot be used try for coin above it.
        int result;
        if((amount - coins[index])<0) {
            result = coinChange(amount, index+1, coins, memo);
        }
        // if we can use the coin add it as well
        else {
            result = coinChange(amount - coins[index], index, coins, memo)
            +coinChange(amount, index+1, coins, memo);
        }
        memo[index][amount] = result;
        return result;
    }
};
