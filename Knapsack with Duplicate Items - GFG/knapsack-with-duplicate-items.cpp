//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index, int wt[], int val[], int W, int n,  vector<vector<int>>& dp) {
            if(index >= n ) {
                return 0;
            }
            
            if(dp[index][W] != -1) {
                return dp[index][W] ;
            }
            if(wt[index] > W) {
                return solve(index + 1, wt, val, W, n, dp);
            }
            
            int include = val[index] + solve(index, wt, val, W - wt[index], n, dp);
            int exclude = solve(index + 1, wt, val, W, n, dp);
            
            return dp[index][W] = max(include, exclude);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
               vector<vector<int>> dp(N + 1, vector<int> (W + 1, -1));

        return solve(0, wt, val, W, N, dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends