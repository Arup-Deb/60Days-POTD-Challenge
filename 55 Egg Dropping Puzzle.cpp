//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int v[201][201]={};
    int eggDrop(int n, int k) 
    {
        if(k==0 || k==1 || n ==1) return k;
        if(v[n][k]) return v[n][k];
        
        int mn = INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int temp =1+ max(eggDrop(n-1, i-1), eggDrop(n, k-i));
            mn = min(mn, temp);
        }
        return v[n][k]=mn;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends