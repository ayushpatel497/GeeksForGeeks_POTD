//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static cmp(Job a, Job b){
        return a.dead < b.dead;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        // your code here
        sort(arr, arr+n, cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int curr = 1;
        for(int i = 0; i < n; i++){
            if(arr[i].dead >= curr){
                pq.push(arr[i].profit);
                curr++;
            }else {
                if(arr[i].profit > pq.top()){
                    pq.push(arr[i].profit);
                    pq.pop();
                }
            }
        }
        int total = 0;
        int job = pq.size();
        
        while(!pq.empty()){
            total += pq.top();
            pq.pop();
        }
        return {job, total};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends