//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long sum=0;
        long long ans=0;
        for(int i=0;i<n;i++)
            sum +=a[i],ans +=(1ll*i*a[i]);
        long long prev_sum=ans;
        for(int i=0;i<n;i++){
            prev_sum=prev_sum-(sum-a[i])+(1ll*a[i]*(n-1));
            ans=max(ans,prev_sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends