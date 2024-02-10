//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    long long helper(vector<vector<int>> &arr, int i, int j, int k, vector<vector<vector<long long>>> &dp)
    {
        if(i<0|| j<0 || k<0)
            return 0;
        if(i==0 && j==0)
        {
            if(k==arr[i][j])
                return 1;
            return 0;
        }
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        long long up = helper(arr, i-1, j, k-arr[i][j], dp);
        long long left = helper(arr, i, j-1, k-arr[i][j], dp);
        return dp[i][j][k] = up + left;
    }
public:
    long long numberOfPath(int n, int k, vector<vector<int>> &arr)
    {
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k+1, -1)));
        return helper(arr, n-1, n-1, k, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends