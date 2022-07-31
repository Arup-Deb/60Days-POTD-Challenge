//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
// 	bool check_elements(int arr[], int n, int A, int B)
// 	{
	
// 	  if(n<=B-A) return false;
// 	    for(int i=0;i<n;i++){
// 	        if(abs(arr[i])>=A && abs(arr[i])<=B){
//     	        int idx=abs(arr[i])-A;
//     	        if(arr[idx]>0) arr[idx]*=-1;
// 	        }
// 	    }
// 	    for(int i=0;i<=B-A;i++){
// 	        if(arr[i]>0) return false;
// 	    }
// 	    return true;
// 	}
bool check_elements(int arr[], int n, int A, int B)
	{
		// Your code goes here
		int c=0;
	unordered_set<int> s;
    for (int i=0;i<n;i++) {
        s.insert(arr[i]);
    }
   vector<int> v(s.begin(), s.end());
		    for(int i=0;i<s.size();i++)
		    {
		        if(v[i]>=A && v[i]<=B)
		        {
		            c++;
		        }
		    }
		    if(c==(B-A+1))
		    {
		        return 1;
		    }
		    else
		    {
		        return 0;
		    }
		
		
	}



		 

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends