class Solution {
public:
    int solve(int index, int n, vector<int>& dp) {
        if(index > n) {
            return 0;
        }
        if(index == n) {
            return 1;
        }
        
        if(dp[index] != -1) {
            return dp[index];
        }
        int oneStep = solve(index + 1, n, dp);
        int twoStep = solve(index + 2, n, dp);
        
        return dp[index] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        int index = 0;
        vector<int> dp(n + 1, -1);
        return solve(index, n, dp);
    }
};