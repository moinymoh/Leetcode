class Solution {
public:
    int solve(int index, vector<int>& prices, bool canBuy, int transAllowed, int n,  vector<vector<vector<int>>>& dp) {
        if(transAllowed == 0 || index == n) {
            return 0;
        }
        
        if(dp[index][canBuy][transAllowed] != -1) {
            return dp[index][canBuy][transAllowed];
        }
        if(canBuy) {
            int buy = -prices[index] + solve(index + 1, prices, !canBuy, transAllowed, n, dp);
            int idle = solve(index + 1, prices, canBuy, transAllowed, n, dp);
            return dp[index][canBuy][transAllowed] = max(buy, idle);
        } else {
            int sell = prices[index] + solve(index + 1, prices, !canBuy, transAllowed - 1, n, dp);
            int idle = solve(index + 1, prices, canBuy, transAllowed, n, dp);
            return dp[index][canBuy][transAllowed] = max(sell, idle);
        }
    }
    int maxProfit(vector<int>& prices) {
        int index = 0;
        int n = prices.size();
        bool canBuy = true;
        int transAllowed = 2;
        // vector<vector<int>> dp(n+1, vector<int> (2, -1));
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, -1)));

        return solve(index, prices, canBuy, transAllowed, n, dp);
    }
};