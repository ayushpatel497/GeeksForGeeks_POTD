//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int gcd(long long int a, long long int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long int getBoundaryCount(long long int p[], long long int q[]) {
        if (p[0] == q[0]) return abs(p[1] - q[1]) - 1;
        if (p[1] == q[1]) return abs(p[0] - q[0]) - 1;
        return gcd(abs(p[0] - q[0]), abs(p[1] - q[1])) - 1;
    }

    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
        // code here
        long long int BoundaryPoints = getBoundaryCount(p, q) + getBoundaryCount(p, r) + getBoundaryCount(q, r) + 3;
        long long int doubleArea = abs(
            p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));
        return (doubleArea - BoundaryPoints + 2) / 2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends