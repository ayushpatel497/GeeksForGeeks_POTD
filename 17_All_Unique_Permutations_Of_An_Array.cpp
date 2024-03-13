//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    void helper(vector<int> arr,vector<int>temp,vector<vector<int>> &ans, int idx, map<vector<int>,int>&hash){
        if(temp.size()==arr.size()){
            if(hash.find(temp)==hash.end()){
                ans.push_back(temp);
                hash[temp]=1;
            }
            return;
        }
        else{
            for(int i=idx;i<arr.size();i++){
                temp.push_back(arr[i]);
                swap(arr[idx],arr[i]);
                helper(arr,temp,ans,idx+1,hash);
                temp.pop_back();
                swap(arr[i],arr[idx]);
            }
        }
    }
public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        map<vector<int>,int>hash;
        helper(arr,temp,ans,0,hash);
        sort(begin(ans),end(ans));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
