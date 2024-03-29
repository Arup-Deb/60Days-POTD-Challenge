//{ Driver Code Starts
// A program to check if a given binary tree is complete or not
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
    

class Solution{
public:    
// void inorder(Node* root,vector<int> &an)
// {
//     if(!root) return ;
    
//     inorder(root->left, an);
//     if(root==NULL) continue;
//     else
//     {
//         an.push_back(root->data);
//     }
//     inorder(root->right,an);
    
//     return (an.size());
// }
    bool isCompleteBT(Node* root){
    //   vector<int> ans;
    //   int p=inorder(root, ans);
    //   if(p==2) return true;
    //   if(p%2==0) return false;
       
    //   return true;
     queue<Node* > q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            Node* t = q.front();
            if(t == NULL) v.push_back(-1);
            else{
                v.push_back(t->data);
                q.push(t->left);
                q.push(t->right);
            }
            q.pop();
        }
        int i = 0;
        for( ; i<v.size() ; i++)
            if(v[i] == -1) break;
        i++;
        for(;i<v.size();i++)
            if(v[i] > -1) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
        if(ob.isCompleteBT(root)){
            printf ("Complete Binary Tree\n");
        }
        else{
            printf ("Not Complete Binary Tree\n");
        } 
    }
    return 0;
}





// } Driver Code Ends