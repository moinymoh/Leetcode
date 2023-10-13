class Solution {
public:
    bool solve(vector<int>& piles, int h, int bananaAte) {
        long long hoursTaken = 0;
        // cout<< bananaAte;
        for(int i = 0; i < piles.size(); i++) {
            hoursTaken += ceil((double)piles[i] / (double)bananaAte);
            // cout << hoursTaken<< endl;
        }
         // cout<< endl;
        return hoursTaken <= h ? true: false;
    }
    int smallestDivisor(vector<int>& piles, int threshold) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(solve(piles, threshold, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};