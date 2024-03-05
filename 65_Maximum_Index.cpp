//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        if(n==1)
            return 0;
        int i, j, maxx;
        
        int *LMin = new int[n];
        int *RMax = new int[n];
        
        LMin[0] = a[0]; 
        for (i = 1; i < n; ++i) 
            LMin[i] = min(a[i], LMin[i-1]); 
            
        RMax[n-1] = a[n-1]; 
        for (j = n-2; j >= 0; --j) 
            RMax[j] = max(a[j], RMax[j+1]); 
         
        i = 0, j = 0, maxx = -1; 
        while (j < n && i < n) 
        { 
            if (LMin[i] <= RMax[j]) 
            { 
                maxx = max(maxx, j-i); 
                j = j + 1; 
            } 
            else
                i = i+1; 
        }
        return maxx; 
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends