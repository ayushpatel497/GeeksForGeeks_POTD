//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1e9+7;
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        // your code here
        int n = s.length();
        long long ans = s[0]-'0';
        long long prev=ans;
        long long current=0;
        for(int i = 1; i < n; i++){
            current = ((i+1)*(s[i]-'0') + 10 * prev)%mod;
            ans+=current;
            prev=current;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends