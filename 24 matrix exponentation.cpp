// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
/*
    int FindNthTerm(long long int n) {
        if(n==0 || n==1)    return 1;
       
       vector<long long int>p(n+1,0);
       int mod=1e9+7;
       
       p[0]=1;
       p[1]=1;
       
       for(int i=2;i<=n;i++){
           p[i]=((p[i-1])%mod+(p[i-2])%mod)%mod;
       }
       
       return p[n]%mod;
    }
};
*/
  typedef long long ll;
   const ll mod = 1e9 + 7;

   void mul(ll mat[2][2], ll mat2[2][2]){
       ll a = ((mat[0][0]*mat2[0][0]) + (mat[0][1]*mat2[1][0]))%mod;
       ll b = ((mat[0][0]*mat2[0][1]) + (mat[0][1]*mat2[1][1]))%mod;
       ll c = ((mat[1][0]*mat2[0][0]) + (mat[1][1]*mat2[1][0]))%mod;
       ll d = ((mat[1][0]*mat2[0][1]) + (mat[1][1]*mat2[1][1]))%mod;
       mat[0][0] = a;
       mat[0][1] = b;
       mat[1][0] = c;
       mat[1][1] = d;
   }

   int FindNthTerm(long long int n) {        
       ll mat[2][2] = {{0,1},{1,1}};
       ll ans[2][2] = {{1,0},{0,1}};        
       ++n;
       while(n){
           if(n&1){
               mul(ans,mat);
           }
           mul(mat,mat);
           n >>= 1;
       }
       return ans[0][1]*1 ;
   }
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends