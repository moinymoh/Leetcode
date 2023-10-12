class Solution {
public:
    int mySqrt(int n) {
        if(n == 0) return 0;
        long long low = 1;
    long long high = n;
    long long ans = -1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;

        long long val = mid * mid;

        if(val <= (long long)n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
    }
};