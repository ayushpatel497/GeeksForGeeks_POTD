//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void helper(string num, int diff, int remaining, vector<string> &ans)
	{
		if (remaining == 0) {
			ans.push_back(num);
			return;
		}
		helper(num + "1", diff + 1, remaining - 1, ans);
		if (0 < diff) 
			helper(num + "0", diff - 1, remaining - 1, ans); 
	}
	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
		vector<string> ans;
		helper("", 0, n, ans);
		return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends