//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int i=0,sign=1,ans=0;
        if(s[0]=='-'){
            sign=-1;
            i++;
        }
        while(i<s.length()){
            if(s[i]<'0' || s[i]>'9')
                return -1;
            ans=ans*10+s[i]-'0';
            i++;
        }
        return sign*ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends