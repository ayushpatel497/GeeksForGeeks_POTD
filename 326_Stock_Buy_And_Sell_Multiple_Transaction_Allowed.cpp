//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int max=0;
        int i=0,j=1;
        int sum=0;
        while(j<prices.size()){
            int value=prices[j]-prices[i];
            if(max>value){
                i=j;
                sum+=max;
                max=0;
            }else{
                max=value;
            }
            j++;
        }
        return sum+max;
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
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends