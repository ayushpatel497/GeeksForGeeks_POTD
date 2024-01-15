//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int dpf(int i, int j, vector<vector<int> > &memo, vector<int> &cost)
    {
        if(i==memo.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        memo[i][j] = dpf(i+1,j,memo,cost);
        if(j >= cost[i])
        {
            memo[i][j] = max(memo[i][j], 1 + dpf(i+1, j - cost[i] + ((9*cost[i])/10), memo, cost));
        }
        return memo[i][j];
    }
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int> > memo(n,vector<int>(total+1,-1));
        return dpf(0,total,memo,cost);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends