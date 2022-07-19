//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
// 	vector<int> constructLowerArray(int *arr, int n) {
// 	   vector<int>v;
	   
// 	   for(int i=0;i<n;i++)
// 	   {
// 	       int c=0;
// 	       for(int j=i+1;j<n;j++)
// 	       {
// 	           if(arr[j]<arr[i])
// 	           {
// 	               c++;
// 	           }
// 	       }
// 	       v.push_back(c);
// 	   }
// 	   return v;
class Node{
   public:
int data ;
   int count;
   Node* right;
   Node* left;
   Node(int data,int count){
       this->data=data;
       this->count=count;
       this->left=NULL;
       this->right=NULL;
   }
};
int helper(int val,Node* &root,int total){
   if(root==NULL){
       root=new Node(val,0);
       return total;
   }
   if(root->data<val){
       return root->count+helper(val,root->right,total+1);
   }
   else {
       root->count++;
       return helper(val,root->left,total);
   }
}
vector<int> constructLowerArray(int *arr, int n) {
  vector<int> v(n);
  Node* root=NULL;
  for(int i=n-1;i>=0;i--){
      v[i]=helper(arr[i],root,0);
  }
  return v;
	   
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
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends