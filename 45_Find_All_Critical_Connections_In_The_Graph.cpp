//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	vector<vector<int>> g, ans;
    vector<int> disc,low,par;
    int time=0;
    void dfs(int u)
    {
        disc[u]=low[u]=time++; 
        int l=g[u].size();
        for(int i=0;i<l;i++)
        {
            int v=g[u][i];
            if((disc[v]==-1))
            {
                par[v]=u;
                dfs(v);
                if(low[v]>disc[u])ans.push_back({u,v});
                low[u]=min(low[u],low[v]); 
            }
            else if(v!=par[u])  
                low[u]=min(low[u],low[v]);
        }
    }
    
    vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
        g=vector<vector<int>>(v);
        par=vector<int>(v,-1);
        low=vector<int>(v,-1);
        disc = low;
        for(int i=0; i<v; i++)
            for(int j=0; j<adj[i].size(); j++)
                g[i].push_back(adj[i][j]);
        for(int i=0 ; i<v; i++)
            if(disc[i]==-1)
                dfs(i);
        for(int i=0;i<ans.size();i++)
            if(ans[i][0]>ans[i][1])
                swap(ans[i][0],ans[i][1]);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends