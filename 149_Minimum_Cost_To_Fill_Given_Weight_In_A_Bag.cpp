//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<int>prev(w+1,1e9),curr(w+1);
        prev[0]=0;
        for(int i=0;i<n;i++){
            curr[0]=0;
            for(int k=0;k<=w;k++){
                int take=1e9;
                if(k>=(i+1)&& cost[i]!=-1)
                    take=cost[i]+curr[k-i-1];
                int nott=prev[k];
                curr[k]=min(take,nott);
            }
            prev=curr;
        }
        if(prev[w]>1e8)
            return -1;
        return prev[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends