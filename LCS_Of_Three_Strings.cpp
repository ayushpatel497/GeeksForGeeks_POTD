//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
        int dp[21][21][21];
        int solve(string &a, string &b, string &c, int i, int j, int k){
            if(i<0 || j<0 || k<0)
                return 0;
            if(dp[i][j][k]!=-1)
                return dp[i][j][k];
            if(a[i]==b[j] && b[j]==c[k])
                dp[i][j][k] = 1+solve(a,b,c,i-1,j-1,k-1);
            else
                dp[i][j][k] = max(solve(a,b,c,i-1,j,k),max(solve(a,b,c,i,j-1,k),solve(a,b,c,i,j,k-1)));
            return dp[i][j][k];
        }
        
    public:
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            memset(dp,-1,sizeof(dp));
            return solve(A,B,C,n1-1,n2-1,n3-1);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends