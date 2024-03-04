//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    long long nCr(long long n, long long r)
    {
        if(n < r)
            return 0;
        long long res = 1;
        for(int i=1; i<=r; ++i)
            res = res * (n-r+i)/i;
        return res;
    }
    
    long long reachLast(int bit, int k)
    {
        long long res = 1;
        for(int i=1; i < k; ++i)
            res += nCr(bit, i);
        return res;
    }
    
    long long rep(int n, int k, int bit)
    {
        long long res = 1L << bit;
        if(n == 1)
            return res;
        for(int cur = bit-1; cur > 0; --cur) {
            long long nextOnes = 1L;
            for(int i=cur-1; i>=0; --i)
                nextOnes += reachLast(i, k);
            if(nextOnes >= n)
                continue;
            --k;
            res |= (1L << cur);
            n -= nextOnes;
            if(n == 1)
                return res;
        }
        if(n == 2)
            res |= 1L;
        return res;
    }
public:
    long long findNthNumber(int n, int k) {
        // code here
        if(--n == 0)
            return 0;
        for(int i=0; i <= 63; ++i) {
            long long res = reachLast(i, k);
            if(n <= res)
                return rep(n, k-1, i);
            n -= res;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
