//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int, int> preSum;
        int maxLen = 0;
        int currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += arr[i];
            int rem = (currSum % k + k) % k;
            if (rem == 0)
                maxLen = max(maxLen, i + 1);
            else if (preSum.find(rem) != preSum.end())
                maxLen = max(maxLen, i - preSum[rem]);
            else
                preSum[rem] = i;
        }
        return maxLen;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
