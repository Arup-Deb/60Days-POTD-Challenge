//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q, int q_i[], int q_j[]) {
        //calculate prefix sum of the matrix
        vector<vector<int>> sum(R+1, vector<int>(C+1));
        
        for(int i=1; i<=R; i++) 
        for(int j=1; j<=C; j++) 
        sum[i][j] = M[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
         
        // Result vector
        vector<int> res(Q);
        
        //Proceed on queries.
        for(int q=0; q<Q; q++) {
            int x = q_i[q]+1, y = q_j[q]+1, val = M[x-1][y-1], side = 1;
            
            while(x-side>=0 and y-side>=0 and x<=R and y<=C) {
                val = sum[x][y] + sum[x-side][y-side] - sum[x-side][y] - sum[x][y-side];
                
                if(val <= K) res[q] = side;
                else { 
                    break;
                }
                
                x += 1; y += 1;
                side += 2;
            }
            
        }
        return res;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R,C,K,Q,x;
        cin>>R>>C;
        vector<vector<int>> M;
        
        for(int a=0; a<R; a++)
        {
            vector<int> temp;
            for(int b=0; b<C; b++)
            {
                cin>>x;
                temp.push_back(x);
            }
            M.push_back(temp);
        }
        
        cin>>K>>Q;
        
        int q_i[Q], q_j[Q];
        
        for(int i=0; i<Q; i++)
            cin>>q_i[i];
        for(int i=0; i<Q; i++)
            cin>>q_j[i];

        Solution ob;
        vector<int> res = ob.largestSquare(M,R,C,K,Q,q_i,q_j);
        
        for(int i=0; i<Q; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends