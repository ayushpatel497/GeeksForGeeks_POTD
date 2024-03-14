//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        int rows[n][n];
        int cols[n][n];

        for (int i = 0; i < n; i++) {
            rows[i][0] = (a[i][0] == 'X' ? 1 : 0);
            for (int j = 1; j < n; j++) {
                if (a[i][j] == 'X')
                    rows[i][j] = rows[i][j - 1] + 1;
                else
                    rows[i][j] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            cols[0][j] = (a[0][j] == 'X' ? 1 : 0);
            for (int i = 1; i < n; i++) {
                if (a[i][j] == 'X')
                    cols[i][j] = cols[i - 1][j] + 1;
                else 
                    cols[i][j] = 0;
            }
        }

        int ans = 0;
        for (int i = n - 1; i >= ans; i--) {
            for (int j = n - 1; j >= ans; j--) {
                int side = min(rows[i][j], cols[i][j]);
                while (side > ans) {
                    if (rows[i - side + 1][j] >= side && cols[i][j - side + 1] >= side)
                        ans = side;
                    else
                        side--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends