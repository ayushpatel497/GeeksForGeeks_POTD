//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> ans;
        ans.push_back(0);
        unordered_map<int, int> mp;
        for(int i = 1;i < n;i++){
            int x = ans[i-1] - i;
            if(x > 0 && mp.find(x) == mp.end()){
                ans.push_back(x);
                mp[x]++;
            }
            else{
                ans.push_back(ans[i-1]+i);
                mp[ans[i-1]+i]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends