//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    // int solve(vector<vector<int>>& g,int i,int j){
    //     if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0) return 0;
    //     g[i][j] = 0;
    //     return 1 + solve(g,i,j+1) + solve(g,i-1,j+1) + solve(g,i+1,j+1) + solve(g,i,j-1) +
    //     solve(g,i+1,j-1) + solve(g,i-1,j-1) + solve(g,i+1,j) + solve(g,i-1,j) ;
    // }
    
    // int findMaxArea(vector<vector<int>>& grid) {
    //     // Code here
    //     int ans = 0;
    //     for(int i=0;i<grid.size();i++){
    //         for(int j=0;j<grid[0].size();j++){
    //             if(grid[i][j]){
    //                 ans = max(ans,solve(grid,i,j));
    //             }
    //         }
    //     }
    
    //     return ans;
    // }
    int findMaxArea(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    res=max(res,fun(grid,i,j));
            }
        }
        return res;
    }
    int fun(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 0;
            
        grid[i][j]=0;
        int t=1;
        t+=fun(grid,i,j-1);
        t+=fun(grid,i,j+1);
        t+=fun(grid,i-1,j);
        t+=fun(grid,i-1,j+1);
        t+=fun(grid,i-1,j-1);
        t+=fun(grid,i+1,j);
        t+=fun(grid,i+1,j+1);
        t+=fun(grid,i+1,j-1);
        
        return t;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends