//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string prefix=arr[0];
        if(arr.size()==1)
            return prefix;
        for(int i=1;i<arr.size();i++)
        {
            int j=0;
            for(j;j<arr[i].length();j++)
            {
                if(arr[i][j]!=prefix[j])
                {
                    break;
                }
            }
            prefix=arr[i].substr(0,j);
        }
        if(prefix=="")
            return "-1";
        return prefix;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends