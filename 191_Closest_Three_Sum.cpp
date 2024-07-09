//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int diff = INT_MAX, maxi=INT_MIN;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0; i<n-2; i++) {
            int l = i+1, r = n-1;
            int sum = 0;
            while(l<r) {
                sum = arr[i]+arr[l]+arr[r];
                int temp = abs(target-sum);
                if(temp==diff) {
                    maxi=max(sum, maxi);
                }else if(temp<diff) maxi=sum, diff=temp;
                if(sum<target) l++;
                else {
                    r--;
                }
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends