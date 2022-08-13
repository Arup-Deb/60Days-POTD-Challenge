//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string str1, str2;
       str1=str2="";
       int temp;
       for(int i=0; i<n; i++){
           temp = str[i];
           if(temp>=97)
           str1+=str[i];
           else
           str2+=str[i];
       }
          string s="";
       sort(str1.begin(), str1.end());
       sort(str2.begin(), str2.end());
       int i=0, j=0;
       for(int t=0; t<n; t++){
           temp=str[t];
           if(temp>=97){
               s+=str1[i];
               i++;
           }
           else{
               s+=str2[j];
               j++;
           }
       }
       return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends