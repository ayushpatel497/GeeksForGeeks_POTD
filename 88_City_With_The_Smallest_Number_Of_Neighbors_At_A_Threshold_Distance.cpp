//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int dijkstra(int n, vector<vector<pair<int, int>>>& graph, int k, int src) {
        priority_queue<int> q;
        q.push(src);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty()) {
            int node = q.top();
            q.pop();
            for (auto x : graph[node]) {
                int nbr = x.first;
                int w = x.second;
                if (dist[nbr] > dist[node] + w) {
                    dist[nbr] = dist[node] + w;
                    q.push(nbr);
                }
            }
        }
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= k)
                ct++;
        }
        return ct;
    }

    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<int> dis(n, 0);
        for (int i = 0; i < n; i++)
            dis[i] = dijkstra(n, graph, distanceThreshold, i);
        int ans = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (ans >= dis[i]) {
                ans = dis[i];
                idx = i;
            }
        }
        return idx;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends