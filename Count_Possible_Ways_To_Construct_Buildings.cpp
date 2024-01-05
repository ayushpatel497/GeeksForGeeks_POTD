//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod=1000000007;
	    long long prev1 = 1, prev2 = 1;
        for(int i = 1; i <= N; i++)
        {
            long long curr = (prev1 + prev2) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return (prev1 * prev1)  % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends