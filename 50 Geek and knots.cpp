//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1000000007;
   long long getNcR(int n, int r) {
       if (r > n-r) r = n-r;
       vector<int> pascalTriangleRow(r+1, 0);
       pascalTriangleRow[0] = 1; 
       for (int i = 1; i <= n; i++) {
           for (int j = min(i, r); j > 0; j--)
               pascalTriangleRow[j] = (pascalTriangleRow[j] + pascalTriangleRow[j - 1]) % mod;
       }
       return pascalTriangleRow[r];
   }
  int knots(int M, int N, int K){
      long long x=getNcR(N,K);
      long long y=getNcR(M,K);
      return (x%mod*y%mod)%mod;
  }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int M, N, K;
        cin>>M>>N>>K;
        
        Solution ob;
        cout<<ob.knots(M, N, K)<<"\n";
    }
    return 0;
}
// } Driver Code Ends