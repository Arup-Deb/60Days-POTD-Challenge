//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
 void dfs(map<string,vector<string>> graph, map<string,bool> &vis,string node, vector<string> &temp){
     temp.push_back(node);
     vis[node]=true;
     for(auto it:graph[node]){
         if(vis[it]==false){
             dfs(graph,vis,it,temp);
         }
     }
 }
   vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
       // code here
       
       map<string,bool> vis;
       map<string,vector<string>> graph;
       vector<vector<string>> ans;
       
       for(auto i : details){
           int j=1;
           for(int j=1;j<i.size()-1;j++){
               string u = i[j];
               string v = i[j+1];
               graph[u].push_back(v);
               graph[v].push_back(u);
           }
       }
       
       for(auto i : details){
           
           string name = i[0];
           
           if(vis[i[1]] == false){
               vector<string> temp;
               // temp.push_back(name);
               dfs(graph,vis,i[1],temp);
               sort(temp.begin(),temp.end());
               vector<string> keep;
               keep.push_back(name);
               for(auto it: temp){
                   keep.push_back(it);
               }
               ans.push_back(keep);
               
           }
       }
       sort(ans.begin(),ans.end());
       reverse(ans.begin(),ans.end());
       return ans;
   }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
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
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends