//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(int i, int j, int n, int m, vector<vector<char>> &a) {
        if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='O') return;
        a[i][j]='O';
        dfs(i,j+1,n,m,a);
        dfs(i,j-1,n,m,a);
        dfs(i+1,j,n,m,a);
        dfs(i-1,j,n,m,a);
    }
    int xShape(vector<vector<char>>& a) {
        int i, j, n=a.size(), m=a[0].size(), ans=0;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(a[i][j]=='X') {
                    dfs(i,j,n,m,a);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends