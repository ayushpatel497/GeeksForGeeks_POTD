//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(heights.size(),vector<int>(heights[0].size(),1e9));
        int n=heights.size();
        int m=heights[0].size();
        pq.push({0,{0,0}});
        dis[0][0]=0;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 and c==m-1)
                return d;
            for(int i=0;i<4;i++)
            {
                int ri=r+x[i];
                int ci=c+y[i];
                if(ri>=0 and ri<n and ci>=0 and ci<m)
                {
                    int maxi=max(abs(heights[r][c]-heights[ri][ci]),d);
                    if(dis[ri][ci]>maxi)
                    {
                        dis[ri][ci]=maxi;
                        pq.push({maxi,{ri,ci}});
                    }
                }
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends