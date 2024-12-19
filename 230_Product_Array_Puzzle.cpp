//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Complete back-end function template for C++


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums)
    {
        // code here
        int n = nums.size();
        long long prod = 1;
        long long flag = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                flag++;
            else
                prod *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (flag > 1)
                nums[i] = 0;
            else if (flag == 0)
                nums[i] = (prod / nums[i]);

           
            else if (flag == 1 && nums[i] != 0)
                nums[i] = 0;

            else
                nums[i] = prod;
        }
        return nums;
    }
};



//{ Driver Code Starts.

int main() {

    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // To ignore newline character after t input

    while (t--) {
        vector<long long> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<long long> vec = obj.productExceptSelf(arr); // Function call

        for (int i = 0; i < vec.size(); i++) { // Print the output
            cout << vec[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
