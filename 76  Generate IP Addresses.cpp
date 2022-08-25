//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
bool check(string &s) {
       
       string temp = "";
       for(int i = 0; i < s.length(); i++) {
           if(s[i] == '.') {
               if(temp.size() > 4 || (temp.size() > 1 && temp[0] == '0') || (stoi(temp) > 255))
                   return false;
                   
               temp = "";
           }
           else
               temp += s[i];
       }
       
       if(temp.size() > 4 || (temp.size() > 1 && temp[0] == '0') || (stoi(temp) > 255))
           return false;
       
       return true;
   }
 
   vector<string> genIp(string &s) {
       
       vector<string> ans;
       if(s.length() < 4) 
           return (ans.push_back("-1"), ans);
       
       for(int i = 1, n = s.length(); i < n - 2; ++i) {
           string x = s.substr(0, i) + '.';
           for(int j = i + 1; j < n - 1; ++j) {
               string y = s.substr(i, j - i) + '.';
               for(int k = j + 1; k < n; ++k) {
                   string z = s.substr(j, k - j) + '.' + s.substr(k);
                   
                   string temp = x + y + z;
                   if(check(temp))
                       ans.push_back(temp);
               }
           }
       }
       
       return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends