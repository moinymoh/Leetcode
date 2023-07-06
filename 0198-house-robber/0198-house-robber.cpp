class Solution {
public:
     int solve(vector<int>& nums, int index, int n, vector<int>& dp){
        if(index >= n){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solve(nums, index + 2, n, dp);
        int exclude = solve(nums, index + 1, n, dp);
        
        return dp[index] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
      
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, n, dp);
    }
};