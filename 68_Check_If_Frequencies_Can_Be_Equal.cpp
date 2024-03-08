//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool allSame(int freq[], int n)
	{
	    int same;
	    int i;
	    for (i = 0; i < n; i++)
	    {
	        if (freq[i] > 0)
	        {
	            same = freq[i];
	            break;
	        }
	    }
	    for (int j = i+1; j < n; j++)
	        if (freq[j] > 0 && freq[j] != same)
	            return false;
	 
	    return true;
	}
	
	bool sameFreq(string str)
	{
	    // code here
	    int m = 26;
	    int l = str.length();
	    int freq[m] = {0};
	    for (int i = 0; i < l; i++)
	        freq[(str[i] - 'a')]++;
	    if (allSame(freq, m))
	        return true;
	    for (char c = 'a'; c <= 'z'; c++)
	    {
	        int i = (c - 'a');
	        if (freq[i] > 0)
	        {
	            freq[i]--;
	            if (allSame(freq, m))
	                return true;
	            freq[i]++;
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends