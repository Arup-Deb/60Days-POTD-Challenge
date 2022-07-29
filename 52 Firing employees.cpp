//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int firingEmployees(vector<int> &arr, int n){
        
        // code here     
        vector<bool> primes(100005,true);
        primes[1] = false;
        for(long int  i = 2;i<=100005;i++){
            if(primes[i]==true)
            for(long int j = i*i;j<=100005;j+=i){
                primes[j] = false;
            }
        }
        
        vector<int> adj[n+1];
        int root = 0;
        for(int i =0;i<n;i++){
            if(arr[i]==0) root = i+1;
            else 
            adj[arr[i]].push_back(i+1);
        }
        int count=0;
        queue<int> q;
        q.push(root);
        vector<int> seniors(n+1);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto v : adj[curr]){
                q.push(v);
                seniors[v] = seniors[curr]+1;
            }
        }
        for(int i =1;i<=n;i++){
            if(i!=root){
                if(primes[i+seniors[i]]){
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.firingEmployees(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends