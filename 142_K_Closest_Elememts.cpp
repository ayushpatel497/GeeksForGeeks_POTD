//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int> result;
        vector<int> closest;
        int l = findCrossOver(arr, 0, n - 1, x);
        int r = l + 1;
        int count = 0;

        if (arr[l] == x)
            l--;
            
        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] < arr[r] - x) {
                closest.push_back(arr[l]);
                l--;
            } else {
                closest.push_back(arr[r]);
                r++;
            }
            count++;
        }
        while (count < k && l >= 0) {
            closest.push_back(arr[l]);
            l--;
            count++;
        }
        while (count < k && r < n) {
            closest.push_back(arr[r]);
            r++;
            count++;
        }
        for (int i = 0; i < k; i++)
            result.push_back(closest[i]);
        return result;
    }

  private:
    int findCrossOver(vector<int>& arr, int low, int high, int x) {
        if (arr[high] <= x) {
            return high;
        }
        if (arr[low] > x) {
            return low;
        }
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        return findCrossOver(arr, low, mid - 1, x);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends