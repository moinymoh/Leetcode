class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            
            if(nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};