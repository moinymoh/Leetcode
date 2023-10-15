//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        int n = x.size();
        for(int i = 0; i < n; i++) {
            char ch = x[i];
            
            if(ch == '{' || ch == '(' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) {
                    return false;
                } else if(st.top() == '{' && ch == '}') {
                    st.pop();
                } else if(st.top() == '[' && ch == ']') {
                    st.pop();
                } else if(st.top() == '(' && ch == ')') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty() ? true: false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends