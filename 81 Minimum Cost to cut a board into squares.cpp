//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        int r = 1, c = 1, i = m-2, j = n-2;
        int ans = 0;
        
        while(i >= 0 && j >= 0) {
            if(x[i] > y[j]) {
                ans += x[i]*r;
                c++;
                i--;
            }
            else{
                ans += y[j]*c;
                r++;
                j--;
            }
        }
        while(i >= 0) {
            ans += x[i]*r;
            c++;
            i--;
        }
        while(j >= 0) {
            ans += y[j]*c;
            r++;
            j--;            
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends