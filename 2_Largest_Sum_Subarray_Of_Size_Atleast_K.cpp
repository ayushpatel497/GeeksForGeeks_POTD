//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int kWinSum=0;
        for(int i=0; i<k; i++)
            kWinSum += a[i];
        long long int prevSum=kWinSum;
        long long int maxSum=kWinSum;
        for(int j=(int)k, i=0; j<n; j++,i++) {
            kWinSum = kWinSum + a[j] - a[i];
            prevSum = max(kWinSum, prevSum+a[j]);
            maxSum = max(maxSum, prevSum);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
