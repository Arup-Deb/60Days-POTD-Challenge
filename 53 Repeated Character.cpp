//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        string p[0]=-1;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i+1;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                    return s[i];
                }
            }
        }
        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends