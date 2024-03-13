//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp(int i,int j,int n,int m,vector<vector<int>>&memo){
        if(j==0)
            return 1;
        if(i>m)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        int take=dp(i*2,j-1,n,m,memo);
        int skip=dp(i+1,j,n,m,memo);
        return memo[i][j]=take+skip;
    }
public:
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>>memo(m+1,vector<int>(n+1,-1));
        return dp(1,n,n,m,memo);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
