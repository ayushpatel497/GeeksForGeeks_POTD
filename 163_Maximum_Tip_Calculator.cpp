//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    static bool comp(vector<int> &v1, vector<int> &v2) { 
        return v1[2] > v2[2]; 
    }
    
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            vector<int> vv(3);
            vv[0] = arr[i], vv[1] = brr[i], vv[2] = abs(arr[i] - brr[i]);
            v[i] = vv;
        }
        sort(v.begin(), v.end(), comp);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (x == 0) {
                ans += v[i][1];
            } else if (y == 0) {
                ans += v[i][0];
            } else {
                if (v[i][0] > v[i][1]) {
                    ans += v[i][0];
                    x--;
                } else {
                    ans += v[i][1];
                    y--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends