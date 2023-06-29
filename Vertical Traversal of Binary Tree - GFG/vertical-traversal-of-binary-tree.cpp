//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
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
    Node* root = newNode(stoi(ip[0]));
          
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //HD -> Horizontal Distance , Lvl -> Level
        
        //create a mapping
        //map< HD, map<Lvl, nodes> > nodes;
        map<int, map<int, vector<int> > > nodes;
        
        //create a queue
        //queue <pair <node, pair<HD, Lvl> >
        queue< pair<Node*, pair<int,int> > > que;
        
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        //put the initial values
        que.push({root,{0,0}});
        
        while(!que.empty()){
           
           //take out the front values
           pair<Node*, pair<int,int> > temp = que.front();
           que.pop();
           
           Node* node = temp.first;
           int hd = temp.second.first;
           int lvl = temp.second.second;
           
           //push out the element into the map
           nodes[hd][lvl].push_back(node->data);
           
           //push the left and right part into queue
            if(node->left)
                que.push( {node->left, {hd-1, lvl+1 } } );
            
            if(node->right)
                que.push( {node->right, {hd+1, lvl+1 } } );
            
        }
        
        for(auto i : nodes){//pair<int, map<int, vector<int> > > 
            
            for(auto j : i.second){//map<int, vector<int> >
                
                for(auto k : j.second){//vector<int>
                
                    ans.push_back(k);
                
                }
            }
            
        }
        
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends