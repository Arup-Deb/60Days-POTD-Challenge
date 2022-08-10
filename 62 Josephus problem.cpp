// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k) {
        vector <int> myVec;
        for (int i = 0; i < n; i++) {
        	myVec.push_back(i+1);
        }    		
        int i = k - 1;
        while (myVec.size() > 1) {
            i %= myVec.size();
            myVec.erase(myVec.begin() + i);
            i += k - 1;
        }
        return myVec[0];
}
 
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends