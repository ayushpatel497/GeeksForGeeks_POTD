//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++
vector<int> bit((int)1e6 + 1);

class Solution {
  public:
    void update(int i, int p) {
        for (; i < (int)1e6 + 1; i += i & (-i)) {
            bit[i] += p;
        }
    }
    int get(int i) {
        int ans = 0;
        for (; i > 0; i -= i & (-i)) {
            ans += bit[i];
        }
        return ans;
    }
    vector<int> constructLowerArray(vector<int>& a) {
        // code here
        int n = a.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) {
            p.emplace_back(a[i], i);
        }
        sort(p.begin(), p.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2) {
                 return p1.first < p2.first;
             });
        int in = 1;
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++) {
            if (hm.find(p[i].first) == hm.end()) {
                hm[p[i].first] = in++;
            }
        }
        for (int i = 0; i < n; i++) {
            a[i] = hm[a[i]];
        }
        fill(bit.begin(), bit.end(), 0);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = get(a[i] - 1);
            update(a[i], 1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends