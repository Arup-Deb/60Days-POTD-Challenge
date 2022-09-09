//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int N)
	{
	    int num = N;
	    int cnt = 0;
	    while(num > 9){
	        num-=9;
	        cnt++;
	    }
	    string str = to_string(num);
	    for(int i=0;i<cnt;i++) {
	        str +='9';
	}
	
	for(int i=0;i<N;i++){
	    str +='0';
	}
	return str;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends