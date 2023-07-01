//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int findIndex(int in[],int inStart,int inEnd,int element){
    
    for(int i = inStart; i <= inEnd; i++){
        if(in[i] == element)
            return i;
    }
    
    return -1;
}

Node* solve(int in[], int post[], int n, int inStart, int inEnd, int &postIndex){
    
    //base case
    if(postIndex < 0 || inStart > inEnd)
        return NULL;
    
    //make current node and decrement postIndex
    int element = post[postIndex--];
    Node* root = new Node(element);
    
    //find the position of the element in inorder array
    int position = findIndex(in,inStart,inEnd,element);
    
    //
    root->right = solve(in,post,n,position+1, inEnd, postIndex);
    root->left = solve(in,post,n,inStart,position-1, postIndex);
    
    return root;
    
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    
    int inStart = 0;
    int inEnd = n-1;
    int postIndex = n-1;
    
    Node* ans = solve(in,post,n,inStart,inEnd,postIndex);
    
    return ans;
    
}
