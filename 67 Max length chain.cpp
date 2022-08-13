//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
       vector<vector<int>>ans;
       for(int i=0;i<n;i++)
       {
           vector<int>d;
           d.push_back(p[i].first);
           d.push_back(p[i].second);
           ans.push_back(d);
       }
       sort(ans.begin(),ans.end(),[&](vector<int>&a,vector<int>&b){
           return a[1]<b[1];
       });
       int fin=1;
       int end=ans[0][1];
       for(int i=1;i<ans.size();i++)
       {
           if(end<ans[i][0])
           {
               fin++;
               end=ans[i][1];
           }
       }
       return fin;
   }
   
    
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends