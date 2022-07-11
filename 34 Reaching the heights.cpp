// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
   vector<int>ans;
    if(n==1){
        ans.push_back(a[0]);
        return ans;
    }
    // Complete the function
    sort(a,a+n);
    int start=0;
    int end=n-1;
    if(a[0]==a[end]){
        ans.push_back(-1);
    return ans;
    }
    int flag=1;
    while(start<=end){
        if(flag==1){
        ans.push_back(a[end]);
        end--;
        }
        else{
            ans.push_back(a[start]);
            start++;
        }
        flag=!flag;
    }
    return ans;
}
