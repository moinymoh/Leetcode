class Solution {
public:
    int solve(vector<int>& cost, vector<int>& dp, int index){
        if(index >= cost.size()){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        int oneStep = cost[index] + solve(cost, dp, index + 1);
        int twoStep = cost[index] + solve(cost, dp, index + 2);
        
        return dp[index] = min(oneStep, twoStep);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(cost, dp, 0), solve(cost, dp, 1));
    }
};