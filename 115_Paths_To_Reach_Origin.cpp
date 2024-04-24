//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod=1e9+7;
    int helper(int n, int m, vector<vector<int>>& paths) {
        if (n == 0 || m == 0)
            return 1;
        if (paths[n][m] != -1)
            return paths[n][m];
        paths[n][m] = (helper(n-1, m, paths) + helper(n, m-1, paths)) % mod;
        return paths[n][m];
    }
    
    int ways(int n, int m) {
        // code here
        vector<vector<int>> paths(n+1, vector<int>(m+1, -1));
        return helper(n, m, paths);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends