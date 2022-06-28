// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
 void reve(stack<int>&St,vector<int>&r)
{
     if(St.empty()) return ;
        
        r.push_back(St.top());
        St.pop();
        reve(St,r);
        return;
}
    vector<int> Reverse(stack<int> St){
        vector<int> rev;
        //base condition
       reve(St,rev);
       return rev;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends