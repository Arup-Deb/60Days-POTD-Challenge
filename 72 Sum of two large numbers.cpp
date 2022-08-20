//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
 //   string helper(string res){
//      int i=0;
//      while(i<res.length() and res[i]=='0')
//      {
//          i++;
//      }
//      if(i==res.length()){
//          return "0";
//      }
//      return res.substr(i);
//  }
 
//   string findSum(string X, string Y) 
//   {
       
//       int n1=X.length()-1;
//       int n2=Y.length()-1;
//       string res="";
//       int a=0,b=0,carry=0;
//       while(n1>=0 || n2>=0){
//           a=0,b=0;
//           if(n1>=0){
//               a=X[n1--]-'0';
//           }
//           if(n2>=0){
//               b=Y[n2--]-'0';
//           }
//           int c=a+b+carry;
//           res+=to_string(c%10);
//           carry=c/10;
//       }
//       if(carry){
//           res+=to_string(carry);
//       }
//       reverse(res.begin(),res.end());
//       return helper(res);
////////////////////////////////////////////////////////////////////////////////////////
  string findSum(string X, string Y) {
           string ans;
       int c=0, i=X.length()-1, j = Y.length()-1;
       while(i>=0 || j>=0)
       {
           if(i>=0)
           {
               c += (X[i--]-'0');
           }
           if(j>=0)
           {
               c += (Y[j--]-'0');
           }
           
           ans += to_string(c%10);
           c /= 10;
       }
       ans += to_string(c);
       for(int k=ans.size()-1;k>0;k--)
       {
           if(ans[k]=='0')
           ans.pop_back();
           else break;
       }
       reverse(ans.begin(), ans.end());
       return ans;
   }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends