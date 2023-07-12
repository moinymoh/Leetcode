class Solution {
public:
    int solve(vector<int> &cost, int index, int n, vector<int>& dp) {
        if(index > n){
            return 10001;
        }
        if(index == n) {
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        int include = cost[index] + solve(cost, index + 1, n, dp);
        int exclude = cost[index] + solve(cost, index + 2, n, dp);
        
        return dp[index] = min(include, exclude);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(cost, 0, n, dp), solve(cost, 1, n, dp));
    }
};