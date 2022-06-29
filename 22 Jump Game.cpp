// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  /*
     bool f(int i,int A[],int N)
  {
      if(i >= N-1)
      return true;
      if(A[i] == 0)
      return false;
      int t = A[i];
      while(t--)
      {
          if(f(i+A[i],A,N))
          return true;
          
          A[i]--;
      }
      return false;
  }
    int canReach(int A[], int N) {
       
        if(f(0,A,N))
        {
            return 1;
        }
        else
        return 0;
    }
    */
    int canReach(int A[], int N) {
    int pivot = N-1;
    for(int i=N-1; i>=0; i--)
    {
        if(i+A[i] >= pivot)
            pivot = i;
    }
    return pivot==0;
}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends