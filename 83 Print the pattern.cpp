//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> pattern(int n){
        vector<string> ans (n, "");
        int k = n;
        int cnt = 1;
        int idx = 0;
        while(k > 0){
            int m = k;
            for(int i = 0; i < 2*idx; i++){
                ans[idx] += "-";
            }
            while(m--){
                ans[idx] += to_string(cnt) + "*";
                cnt++;
            }
            idx++;
            k--;
        }
        idx--;
        k = 1;
        while(k <= n){
            int m = k;
            while(m--){
                ans[idx] += to_string(cnt);
                if(m != 0){
                    ans[idx] += "*";
                }
                cnt++;
            }
            idx--;
            k++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans = ob.pattern(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
// } Driver Code Ends