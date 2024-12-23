//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++) {
            if(binarySearch(mat[i], 0, m, x))
            	return true;
        }
        return false;
    }
    
    bool binarySearch(vector<int> arr, int low, int high, int x){
        while(low<=high){
            int mid= low + (high - low)/2;
            if(x==arr[mid]) 
                return true;
            if(x<arr[mid]) 
                high=mid-1;
            if(x>arr[mid]) 
                low=mid+1;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends