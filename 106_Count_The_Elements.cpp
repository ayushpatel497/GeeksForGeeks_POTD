//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        int max1 = -1;
        for (int i = 0; i < n; i++) 
            if (a[i] > max1) 
                max1 = a[i];
                
        int max2 = max1;
        for (int i = 0; i < n; i++) 
            if (b[i] > max2) 
                max2 = b[i];
                
        int h[max2 + 1];
        memset(h, 0, sizeof(h));
        for (int i = 0; i < n; i++){
            int m = b[i];
            h[m]++;
        }
        for (int i = 1; i <= max1; i++)
            h[i] += h[i - 1];
            
        vector<int> ans;
        for (int i = 0; i < q; i++) {
            int k = query[i];
            ans.push_back(h[a[k]]);
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
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends