//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int buy1 = INT_MAX, buy2 = INT_MAX, 
            profit1 = 0, profit2 = 0;
            for(int i : price){
                buy1 = min(buy1, i);
                profit1 = max(profit1, i - buy1);
                buy2 = min(buy2, i - profit1);
                profit2 = max(profit2, i - buy2);
            }
            return profit2;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends