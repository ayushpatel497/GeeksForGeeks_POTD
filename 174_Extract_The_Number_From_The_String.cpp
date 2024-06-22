//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        // code here
        long long int maxi=-1;
        for(int i=0;i<sentence.length();i++)
        {
            long long int num=0;
            bool valid=true;
            while(sentence[i]!=' ' && (sentence[i]>='0' && sentence[i]<='9') && i<sentence.length())
            {
                int x=(sentence[i]-'0');
                if(x==9)
                    valid=false;
                num=(num*10)+x;
                i++;
            }
            if(valid==true)
                maxi=max(maxi,num);
        }
        if(maxi==0)
            return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends