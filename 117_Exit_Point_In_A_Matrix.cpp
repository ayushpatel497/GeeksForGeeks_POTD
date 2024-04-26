//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int i = 0, j = 0;
        int dir = 1;

        while (i < n and j < m and i >= 0 and j >= 0) {

            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                switch (dir) {
                    case 1:
                        dir = 2;
                        break;
                    case 2:
                        dir = 3;
                        break;
                    case 3:
                        dir = 4;
                        break;
                    case 4:
                        dir = 1;
                        break;
                }
            }

            switch (dir) {
                case 1:
                    j++;
                    break;
                case 2:
                    i++;
                    break;
                case 3:
                    j--;
                    break;
                case 4:
                    i--;
                    break;
            }
        }

        switch (dir) {
            case 1:
                j--;
                break;
            case 2:
                i--;
                break;
            case 3:
                j++;
                break;
            case 4:
                i++;
                break;
        }

        return {i, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends