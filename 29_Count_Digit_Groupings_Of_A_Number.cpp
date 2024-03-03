//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	int help(string& s,int i,int pre,vector<vector<int>>& memo)
	{
	    if(i<0)
	    return 1;
	    if(pre!=-1 and memo[i][pre]!=-1)
	        return memo[i][pre];
	    int sum=0;
	    int ans=0;
	    string str="";
	    for(int j=i;j>=0;j--)
	    {
	        sum+=s[j]-'0';
	        if(sum<=pre or pre==-1)
	        ans+=help(s,j-1,sum,memo);
	        else
	        break;
	    }
	    if(pre==-1)
	        return ans;
	    return memo[i][pre]=ans;
	}
	public:
	int TotalCount(string str){
	    vector<vector<int>> memo(str.length()+1,vector<int>(1000,-1));
	    return help(str,str.length()-1,-1,memo);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
