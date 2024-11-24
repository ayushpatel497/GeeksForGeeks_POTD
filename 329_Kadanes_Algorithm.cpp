//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        long long max_so_far = -1e12, max_ending_here = 0;

        for (int i = 0; i < arr.size(); i++) {      
            max_ending_here = max_ending_here + arr[i];
            max_so_far = max(max_so_far, max_ending_here);
            max_ending_here = max(max_ending_here, 0LL);
        }
        
        return max_so_far;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends