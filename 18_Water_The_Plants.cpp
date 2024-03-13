//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>> sprnklr;
        for(int i=0; i<n; i++)
            if(gallery[i] > -1)
                sprnklr.push_back( pair<int,int> ( i-gallery[i], i+gallery[i] ) );
        sort(sprnklr.begin(), sprnklr.end());
        int target=0, ans=0, i=0;
        while(target<n)
        {
            if(i==sprnklr.size() || sprnklr[i].first>target)
                return -1;
            int max_range = sprnklr[i].second;
            while( i+1<sprnklr.size() && sprnklr[i+1].first<=target )
            {
                i++;
                max_range = max( max_range,  sprnklr[i].second );
            }
            if(max_range<target)
                return -1;
            ans++;
            target = max_range +1;
            i++;
        }
        return ans;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends
