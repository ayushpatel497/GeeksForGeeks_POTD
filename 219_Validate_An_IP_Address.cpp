//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int n = str.size();
        if(n<7 || n>15) return false;
        int num = 0;
        int parts = 0;
        for(int i = 0 ; i<n;i++){
            if(i==0 && str[i]=='0' && str[i+1]!='.') return false;
            if(str[i]=='0' && str[i-1]=='.' && str[i+1]!='.')return false;
            if(str[i]!='.' && !isdigit(str[i])) return false;
            if(str[i]=='.'){
                if(i==0 || str[i-1]=='.') return false;
                if(num>255) return false;
                num = 0;
                parts++;
                continue;
            }
            num = (num*10) + (str[i]-'0');
        }
        
        if(parts!=3) return false;
        if(num>255) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends