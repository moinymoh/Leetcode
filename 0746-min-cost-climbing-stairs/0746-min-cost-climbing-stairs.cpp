class Solution {
public:
    int solve(int index, vector<int>& cost, int n, vector<int>& dp) {
        if(index >= n) {
            return 0;
        }
        
        if(dp[index] != -1) {
            return dp[index];
        }
        int oneStep = cost[index] + solve(index + 1, cost, n, dp);
        int twoStep = cost[index] + solve(index + 2, cost, n, dp);
        
        return dp[index] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(0, cost, n, dp), solve(1, cost, n, dp));
    }
};