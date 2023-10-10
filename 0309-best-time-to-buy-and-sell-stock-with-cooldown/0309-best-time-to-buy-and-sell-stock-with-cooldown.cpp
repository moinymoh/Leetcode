class Solution {
public:
    int solve(int index, vector<int>& prices, bool canBuy, int transAllowed, int n, vector<vector<int>>& dp) {
        if(index >= n) {
            return 0;
        }
        
        if(dp[index][canBuy] != -1) {
            return dp[index][canBuy];
        }
        if(canBuy) {
            int buy = -prices[index] + solve(index + 1, prices, !canBuy, transAllowed, n, dp);
            int idle = solve(index + 1, prices, canBuy, transAllowed, n, dp);
            return dp[index][canBuy] = max(buy, idle);
        } else {
            int sell = prices[index] + solve(index + 2, prices, !canBuy, transAllowed, n, dp);
            int idle = solve(index + 1, prices, canBuy, transAllowed , n, dp);
            return dp[index][canBuy] = max(sell, idle);
        }
    }
    int maxProfit(vector<int>& prices) {
        int index = 0;
        int n = prices.size();
        bool canBuy = true;
        int transAllowed = 1;
        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return solve(index, prices, canBuy, transAllowed, n, dp);
    }
};