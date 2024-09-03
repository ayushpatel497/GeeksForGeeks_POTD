//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int func(string str1,string str2,int i,int j,vector<vector<int>>&dp){
        if(i==str1.length()||j==str2.length())
            return 0;
        int one=0,two=0,three=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str1[i]==str2[j])
            one=1+func(str1,str2,i+1,j+1,dp);
        two=func(str1,str2,i+1,j,dp);
        three=func(str1,str2,i,j+1,dp);
        dp[i][j]=max(one,max(two,three));
        return dp[i][j];
    }
    public:
    int minOperations(string str1, string str2) 
    {   
        // Your code goes here
        vector<vector<int>> dp(str1.length(),vector<int>(str2.length(),-1));
        int val=func(str1,str2,0,0,dp);
        return str1.length()-val+str2.length()-val;
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends