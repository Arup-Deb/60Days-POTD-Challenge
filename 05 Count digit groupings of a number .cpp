// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
int solve(int i,string s,vector<vector<int>> &dp,int prev)
	{
	    if(i==s.size()) return 1;
	    if(dp[i][prev]!=-1) return dp[i][prev];
	    int sum=0,ans=0;
	    for(int j=i;j<s.size();j++)
	    {
	        sum+=(s[j]-'0');
	        if(sum>=prev)
	        {
	            ans+=solve(j+1,s,dp,sum);
	        }
	    }
	    return dp[i][prev]=ans;
	}
	int TotalCount(string str){
	    // Code here
	    int n=str.size(),i,sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=(str[i]-'0');
	    }
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    return solve(0,str,dp,0);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends