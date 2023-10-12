class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    
    int upperBound(vector<int> arr, int n, int x) {
	// Write your code here
        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int lb = lowerBound(nums, n, target);
        int ub = upperBound(nums, n, target);
        if(lb == n || nums[lb] != target) {
            return {-1, -1};
        }
        ans.push_back(lb);
        ans.push_back(ub - 1);
        return ans;
    }
};