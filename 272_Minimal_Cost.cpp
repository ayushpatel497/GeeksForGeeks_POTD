//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        unordered_map<int, int> dp;
        int n = arr.size();
        dp[arr[0]] = 0;
        for (int i = 1; i < n; i++) {
            int min_cost = INT_MAX;
            for (int j = i-1; j >= max(0, i-k); j--) {
                int cost = dp[arr[j]] + abs(arr[i]-arr[j]);
                min_cost = min(min_cost, cost);
            }
            dp[arr[i]] = min_cost;
        }
        return dp[arr[n-1]];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends