//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int maxEle = 0;
        for (int i = 0; i < n; i++) {
            maxEle = max(maxEle, arr[i]);
        }
        vector<int> hash(maxEle + 1, 0);
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }
        int count = 0;
        for (int i = 0; i <= maxEle; i++) {
            if (hash[i]) {
                if (i == i + k) {
                    count += (hash[i] * (hash[i] - 1)) / 2;
                } else if (i + k <= maxEle) {
                    count += (hash[i] * hash[i + k]);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends