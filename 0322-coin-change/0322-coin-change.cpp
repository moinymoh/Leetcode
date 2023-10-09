class Solution {
public:
    int solve(int index, vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if(amount == 0) {
            return 0;
        }
        if(index == n && amount != 0) {
            return 10000001;
        }
        
        if(dp[index][amount] != -1){
            return dp[index][amount];
        } 
        
        if(amount < coins[index]) {
            return dp[index][amount] = solve(index + 1, coins, amount, n, dp);
        }
        
        int include = 1 + solve(index, coins, amount - coins[index], n, dp);
        int exclude = solve(index + 1, coins, amount, n, dp);
        
        return dp[index][amount] = min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = solve(0, coins, amount, n, dp);
        return  ans == 10000001 ? -1 : ans;
    }
};