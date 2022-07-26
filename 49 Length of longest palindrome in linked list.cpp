//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include<vector>
bool isPal(vector<int>&temp,int i,int j,vector<vector<int>>&dp)
{
    if(i==j)return true;
    
    else if(i==j-1)return temp[i]==temp[j];
    
    if(dp[i][j]!=-1)return dp[i][j];
    
    if(temp[i]!=temp[j])return dp[i][j]=0;
    
    else return dp[i][j]=isPal(temp,i+1,j-1,dp);
}
int maxPalindrome(Node *head)
{
    vector<int>temp;
    while(head)
    {
        temp.push_back(head->data);
        head=head->next;
    }
    int ans=1,n=temp.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(isPal(temp,i,j,dp))
            ans=max(ans,j-i+1);
        }
    }
    return ans;
}