//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if (n==0 || n==1)
            return n;
        long long int ans=0;
        int left=0;
        int right=n/2;
        while(left<=right)
        {
            long long int mid=left+(right-left)/2;
            if(mid*mid==n)
                return mid;
            if(mid*mid>n)
                right=mid-1;
            else
            {
                ans=mid;
                left=mid+1;
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
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends