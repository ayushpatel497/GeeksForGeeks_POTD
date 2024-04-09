//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	    if (m == 0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n] = 1;
        dp[m][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) 
            for (int j = n - 1; j >= 0; j--) 
                dp[i][j] = max(1, (min(dp[i + 1][j], dp[i][j + 1]) - points[i][j]));
        return dp[0][0];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends