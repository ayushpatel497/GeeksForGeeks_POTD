//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool isValid(int arr[],int reqSum,int k,int n){
        int sum=0,ct=1;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=reqSum)
                sum+=arr[i];
            else{
                sum=arr[i];
                ct++;
            }
        }
        return ct<=k;
    }
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int totalSum=0,maxi=INT_MIN;
        for(int i=0;i<N;i++){
            totalSum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int s=maxi,e=totalSum,ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isValid(arr,mid,K,N)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends