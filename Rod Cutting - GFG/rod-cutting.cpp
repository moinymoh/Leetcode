//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int index, int price[], int N, int n, vector<vector<int>>& dp) {
        if(index >= n) {
            return 0;
        }
        
        if(dp[index][N] != -1) {
                return dp[index][N];
            }
        if(N < (index + 1)) {
            return dp[index][N] = solve(index + 1, price, N, n, dp);
        }
        int include = price[index] + solve(index, price, N - (index + 1), n, dp);
        int exclude = solve(index + 1, price, N, n, dp);
        
        
        return dp[index][N] = max(include, exclude);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(0, price, n, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends