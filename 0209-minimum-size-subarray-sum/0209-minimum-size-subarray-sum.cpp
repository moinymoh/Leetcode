class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int preSum = 0;
        
        int j = 0;
        for(int i = 0; i < n; i++){
            preSum += nums[i];
            
            while(preSum >= target){
                if(preSum >= target){
                    ans = min(ans, i - j + 1);
                }
                preSum -= nums[j];
                j++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};