//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string find(string s, map<string, string> &p) {
        return p[s] == s ? s : find(p[s], p);
    }

    // Function to merge the accounts using union-find data structure.
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parents[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            string p = find(accounts[i][1], parents);
            for (int j = 2; j < accounts[i].size(); j++)
                parents[find(accounts[i][j], parents)] = p;
        }

        for (int i = 0; i < accounts.size(); i++)
            for (int j = 1; j < accounts[i].size(); j++)
                unions[find(accounts[i][j], parents)].insert(accounts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends