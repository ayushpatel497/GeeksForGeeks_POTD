//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isval(int x, int y, int szx, int szy){
        return x>=0 and y>=0 and x<szx and y<szy;
    }
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0};
        int ans=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    for(int ii=0; ii<4; ii++){
                        int newi=i+dx[ii], newj=j+dy[ii];
                        if(isval(newi, newj, matrix.size(), matrix[0].size()) and matrix[newi][newj]==1){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
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
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends