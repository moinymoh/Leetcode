class Solution {
public:
    int solve(int index, vector<int>& nums, int n, int target,  map<pair<int,int>,int>& dp) {
        if(index >= n && target == 0) {
            return 1;
        }
        if(index >= n && target != 0) {
            return 0;
        }
        
       
        pair<int, int> x = make_pair(index, target);

        if(dp.find(x) != dp.end()){
            return dp[x];
        }
        
        int pos = solve(index + 1, nums, n, target + nums[index], dp);
        int neg = solve(index + 1, nums, n, target - nums[index], dp);
        
        return dp[x] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
         map<pair<int,int>,int> dp;
        return solve(0, nums, n, target, dp);
    }
};