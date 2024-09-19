//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        string ans,temp;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '.'){
                ans = '.'+temp + ans;
                temp = "";
            }
            else temp = temp+s[i];
        }
        ans = temp+ans;
        return ans;
    } 
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends