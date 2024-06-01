//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> ch(27,0);
        for(auto it : s)
        {
           int i = abs('a' - it)+1;
           ch[i]++;
        }
        int x=0,y=0;
        for(int i=1;i<=26;i++)
        {
            if(ch[i]!=0){
                if(i%2==0&&ch[i]%2==0)
                    x++;
            else if(i%2!=0 && ch[i]%2!=0)
                y++;
          }
        }
        if((x+y)%2)
            return "ODD";
        return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends