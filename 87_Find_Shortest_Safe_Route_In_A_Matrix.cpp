//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int rowNum[4] = {-1, 0, 0, 1};
    int colNum[4] = {0, -1, 1, 0};
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        queue<array<int,3>> q;
        int d[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                d[i][j] = 1e9;
        
        auto isValid = [&](int i, int j) {
            if(i < 0 || i >= n || j < 0 || j >= m) 
                return false;
            return true;
        };
        
        auto check = [&](int i, int j) {
            if(!isValid(i, j)) 
                return false;
            for(int k = 0; k < 4; k++)
                if(isValid(i + rowNum[k], j + colNum[k]) && !mat[i + rowNum[k]][j + colNum[k]]) 
                    return false;
            return true;
        };
        
        for(int i = 0; i < n; i++)
            if(check(i, m - 1))
                q.push({i, m - 1, 1});
        
        while(!q.empty()) {
            auto z = q.front();
            int x = z[0], y = z[1], dis = z[2];
            q.pop();
            if(d[x][y] > dis) {
                d[x][y] = dis;
                for(int k = 0; k < 4; k++)
                    if(check(x + rowNum[k], y + colNum[k]))
                        q.push({x + rowNum[k], y + colNum[k], dis + 1});
            }
        }
        
        int ans = 1e9;
        for(int i = 0; i < n; i++)
            ans = min(ans, d[i][0]);
        
        if(ans >= 1e9) 
            ans = -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends