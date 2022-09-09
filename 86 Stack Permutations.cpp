//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &a,vector<int> &b){
    //     stack<int> s;
    //   int a=0;
    //   for(auto i:A){
    //       s.push(i);
    //       while(!s.empty() and s.top() == B[a]){
    //           s.pop();
    //           a++;
    //       }
    //   }
    //   if(a == N) return true;
    //   return false;
    stack<int>st;
        int i=0,j=0;
       int n=a.size();
       for( i=0;i<n;i++)
       {
           while(!st.empty() && st.top()==b[j])
           {
               j++;
               st.pop();
           }
           st.push(a[i]);
       }
       while(!st.empty())
       {
           if(st.top()!=b[j])return 0;
           st.pop();
           j++;
       }
       return 1;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends