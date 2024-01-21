//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    bool checkCover(int n, int k, int m, vector<vector<int>> &e) {
    	int set = (1 << k) - 1;
    	int limit = (1 << n);
    	bool visited[n + 1][n + 1];
    	while (set < limit) {
    		memset(visited, 0, sizeof(visited));
    		int cnt = 0;
    		for (int j = 1, v = 1; j < limit; j = j << 1, v++) {
    			if (set & j) {
    				for (int k = 1; k <= n; k++) {
    					if (e[v][k] && !visited[v][k]) {
    						visited[v][k] = 1;
    						visited[k][v] = 1;
    						cnt++;
    					}
    				}
    			}
    		}
    		if (cnt == m) {
    			return true;
    		}
    		int c = set & -set;
    		int r = set + c;
    		set = (((r ^ set) >> 2) / c) | r;
    	}
    	return false;
    }

    int vertexCoverHelper(vector<vector<int>> e, int n, int m) {
    	int low = 1, high = n;
    
    	while (high > low) {
    		int mid = (low + high) >> 1;
    
    		if (checkCover(n, mid, m, e) == false) {
    			low = mid + 1;
    		}
    		else {
    			high = mid;
    		}
    	}
    	return low;
    }

    public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
    	int m = edges.size();
    	vector<vector<int>> e(n + 1, vector<int>(n + 1, 0));
    	for (int i = 0; i < m; i++) {
    		e[edges[i].first][edges[i].second] = 1;
    		e[edges[i].second][edges[i].first] = 1;
    	}
    	return vertexCoverHelper(e, n, m);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends