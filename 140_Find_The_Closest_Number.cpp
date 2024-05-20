//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int getClosest(int val1, int val2, int k) 
    { 
        if (k - val1 >= val2 - k) 
            return val2; 
        else
            return val1; 
    }   
    int findClosest(int n, int k,int arr[]) 
    { 
        // Complete the function 
        if (k <= arr[0]) 
            return arr[0]; 
        if (k >= arr[n - 1]) 
            return arr[n - 1]; 
        int i = 0, j = n, mid = 0; 
        while (i < j) { 
            mid = (i + j) / 2; 
            if (arr[mid] == k) 
                return arr[mid]; 
            if (k < arr[mid]) { 
                if (mid > 0 && k > arr[mid - 1]) 
                    return getClosest(arr[mid - 1], arr[mid], k); 
                j = mid; 
            } 
            else { 
                if (mid < n - 1 && k < arr[mid + 1]) 
                    return getClosest(arr[mid], arr[mid + 1], k); 
                i = mid + 1;  
            } 
        } 
        return arr[mid]; 
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends