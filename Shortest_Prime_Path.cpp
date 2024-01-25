//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int mxp;
    vector<int> prime;
    Solution(){
        mxp=9999;
        prime=vector<int>(10001,1);
        prime[1]=0;
        for(int i=2;i<=mxp;i++){
            if(prime[i]){
                for(int j=2;j*i<=mxp;j++){
                    prime[i*j]=0;
                }
            }
        }
    }
    int bfs(int src, int &dest){
        vector<int>dp(10001,-1);
        vector<int>vis(10001);
        queue<int>q;
        q.push(src);
        dp[src]=0;
        vis[src]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(vis[curr])
                continue;
            vis[curr]=1;
            string s=to_string(curr);
            for(int i=0;i<4;i++){
                for(char ch='0';ch<='9';ch++){
                    if(ch==s[i] || (ch=='0' && i==0))
                        continue;
                    string nxt=s;
                    nxt[i]=ch;
                    int nxtN=stoi(nxt);
                    if(prime[nxtN]&&dp[nxtN]==-1){
                        dp[nxtN]=1+dp[curr];
                        q.push(nxtN);
                    }
                }
            }
        }
        return dp[dest];
    }
    int solve(int Num1,int Num2)
    {   
      //code here
        return bfs(Num1,Num2);
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends