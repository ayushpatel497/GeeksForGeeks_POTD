//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define M 1000000007
class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
        int pPrevPrev = 1, pPrev = 1, pCurr = 1, pNext = 1;
        for (int i=3; i<=n; i++)
        {
            pNext = (pPrevPrev%M + pPrev%M)%M;
            pPrevPrev = pPrev%M;
            pPrev = pCurr%M;
            pCurr = pNext%M;
        }
        return pNext%M;
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends