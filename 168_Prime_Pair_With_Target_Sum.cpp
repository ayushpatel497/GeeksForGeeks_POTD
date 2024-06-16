//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    bool isPrime(int n){
        int cnt = 0; 
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                cnt++;
                if(n/i != i)
                    cnt++;
            }
            if(cnt > 2)
                return false;
        }
        return true;
    }
  public:
    vector<int> getPrimes(int n) {
        for(int i=2; i<=n/2; i++)
            if(isPrime(i))
                if(isPrime(n-i) && n-i != 0)
                    return {i,n-i};
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends