//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if (q>=n){
            long long r = min(q-1, n);
            long long l = max(q-n, 1LL);
            return max((r-l+1), 0LL);
        }
        else {
            return q-1;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends