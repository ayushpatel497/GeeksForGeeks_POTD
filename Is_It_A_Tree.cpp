//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  private:
    void dfs(vector<int>*nds,int node,vector<int>&vis){
        vis[node]=1;
        for(auto i: nds[node]){
            if(!vis[i])
                dfs(nds,i,vis);
        }
    }
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(n-m!=1)
            return 0;
        vector<int>nds[n];
        for(auto i:adj){
            nds[i[0]].push_back(i[1]);
            nds[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        dfs(nds,0,vis);
        for(auto i:vis)
            if(i==0)
                return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends