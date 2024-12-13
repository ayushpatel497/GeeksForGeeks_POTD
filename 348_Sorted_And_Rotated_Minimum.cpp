//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int l = 0, r = arr.size() - 1;

        while (l < r) {
            if (arr[l] < arr[r])        
                return arr[l];
          
            int mid = (l + r) / 2;
            if (arr[mid] > arr[r])
                l = mid + 1;
            else
                r = mid;
        }
    
        return arr[l]; 
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends