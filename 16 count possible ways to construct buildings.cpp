// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	     if(N<3) {
	    return (N+1)*(N+1);
    }
	long long first=2,second=3,total=0;
	for(int i=3;i<=N;i++) {
	    total=(first+second)%1000000007;
	    first=second;
	    second=total;
	}
	return (total*total)%1000000007;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends