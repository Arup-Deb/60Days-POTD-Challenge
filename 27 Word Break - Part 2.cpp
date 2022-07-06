// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

//Using BackTracking in C++

class Solution{
   
public:
   vector<string> solution;
   
   bool wordAvailable(string tmp,vector<string>& dict,int n){
       for(int i=0;i<n;i++){
           if(dict[i]==tmp){
               return true;
           }
       }
       return false;
   }
   
   void breakingWords(int n, vector<string>& dict,string s,int start,string sub){
       if(start == s.length()){
           solution.push_back(sub.substr(0,sub.length()-1));
           return;
       }
       string tmp="";
       for(int i=start;i<s.length();i++){
           tmp+=s[i];
           if(wordAvailable(tmp,dict,n)){
               breakingWords(n,dict,s,i+1,sub+tmp+" ");
           }
       }
   }
   
   vector<string> wordBreak(int n, vector<string>& dict, string s)
   {
       breakingWords(n,dict,s,0,"");
       return solution;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends