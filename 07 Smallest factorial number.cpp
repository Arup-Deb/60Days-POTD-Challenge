// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    /*
        int findNum(int n)
        {
         int ans=0,cnt, s,e,m;
       
       s = 5;
       e = n*5;
       
       while(s<=e){
           m = s+(e-s)/2;
           cnt = 0;
           
           for(int i=5;i<=m;i*=5)
               cnt += m/i;
           
           if(cnt<n)
               s= m+1;
           else{
               ans = m;
               e = m-1;
           }
       }
       
       return ans;
        
        
        }
        */
        int findNum(int n)
    {
        int ans = 0;
        int low = 1;
        int high = 5*n;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int count = 0;
            
            for(int i=5; mid/i >= 1; i *= 5){
                count += mid/i;
            }
            
            if(count >= n){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends