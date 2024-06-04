//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n=s.size();
        bool noZero=true;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                noZero=false;
                break;
            }else{
                s[i]='0';
            }
        }
        if(noZero)
            s="1"+s;
        while(s[0]=='0' && s.size()>1)
            s.erase(s.begin());
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends