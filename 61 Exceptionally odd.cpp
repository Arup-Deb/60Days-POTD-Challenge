//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
       
    //   sort(arr,arr+n);
    //   int c=1;
    //   for(int i=1;i<n;i++)
    //   {
    //       if(arr[i]==arr[i-1])
    //       {
    //           c++;
    //       }
    //       else
    //       {
    //           if(c%2==0)
    //           {
    //               c=1;i++;
    //           }
    //           else
    //           {
    //               return arr[i];
    //           }
    //       }
    //   }
    unordered_map<int,int>P;
       for(int i=0;i<n;i++)
           P[arr[i]]++;
       
       for(auto x:P){
           if(x.second%2!=0)
               return x.first;
    }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends