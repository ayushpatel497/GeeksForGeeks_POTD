//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        int LCSRe[n+1][n+1];
        memset(LCSRe, 0, sizeof(LCSRe));
        string ans;
        int ans_length = 0;
        int i, index = 0;
        for (i=1; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                if ( s[i-1] == s[j-1] && LCSRe[i-1][j-1] < (j - i) )
                {
                    LCSRe[i][j] = LCSRe[i-1][j-1] + 1;
                    if (LCSRe[i][j] > ans_length)
                    {
                        ans_length = LCSRe[i][j];
                        index = max(i, index);
                    }
                }
                else
                    LCSRe[i][j] = 0;
            }
        }
        if (ans_length > 0)
            for (i = index - ans_length + 1; i <= index; i++)
                ans.push_back(s[i-1]);
        if(ans=="")
            ans="-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends