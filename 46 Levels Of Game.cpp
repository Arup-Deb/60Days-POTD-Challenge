//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        // int travel(vector<vector<int>> &dp, vector<pair<int, int>> & vec, int i, int h, int m){
        //     if(h <= 0 || m <= 0){
        //         return 0;
        //     }
        //     if(dp[h][m] != -1){
        //         return dp[h][m];
        //     }
        //     int count = 0;
        //     for(int j = 0; j < 3; j++){
        //         if(i != j && h - vec[j].first > 0 && m - vec[j].second > 0){
        //             count = max(count, 1 + travel(dp, vec, j, h - vec[j].first, m - vec[j].second));
        //         }
        //     }
        //     return dp[h][m] = count;
        // }
    
    
    
        // int maxLevel(int h,int m)
        // {
        //     vector<vector<int>> dp(h + 1000, vector<int> (m + 1000, -1));
        //     vector<pair<int, int>> vec{{-3, -2}, {5, 10}, {20, -5}};
        //     return travel(dp, vec, 3, h, m);
        // }
         int maxLevel(int h,int m)
       {
          int cnt=0;
          while(true){
              if(cnt%2==0){
                h+=3;
                m+=2;
              }
              else{
                  if(m>10){
                      if(h>=5){
                          h-=5;
                          m-=10;
                      }
                      else
                       break;
                  }
                  else if(h>20){
                      h-=20;
                      m+=5;
                  }
                  else
                    break;
              }
              if(h==0 || m==0)
                    break;
              cnt++;
               
          }
          return cnt;
       }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends