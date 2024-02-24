//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int help(int n,vector<int>& memo)
        {
            if(n==0)
                return 0;
            if(memo[n]!=-1)
                return memo[n];
            int sum=help(n/2,memo)+help(n/3,memo)+help(n/4,memo);
            return memo[n] = (sum>=n) ? sum :  n;
        }
        
        int maxSum(int n)
        {
            //code here.
            vector<int> memo(n+1,-1);
            return help(n,memo);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends