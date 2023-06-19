//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    public:
    
    Node* reverseList(Node* head){
        
        Node* prev = NULL;
        Node* iter = head;
        Node* next = NULL;
        
        while(iter != NULL){
            
            next = iter->next;
            iter->next = prev;
            
            prev = iter;
            iter = next;
            
        }
        
        return prev;
    }
    
    Node* add(Node* head){
        
        Node* iter = head;
        
        if(head->data < 9){
            head->data = head->data + 1;
            return head;
        }else{
            
            int sum = iter->data + 1;
            int digit = 0;
            int carry = 1;
            
            Node* ansIter = new Node(-1);//dummy node
            Node* ansHead = ansIter;
            
            ansIter->next = new Node(digit);
            
            iter = iter->next;
            ansIter = ansIter->next;
            
            while(iter != NULL || carry>0){
                
                
                if(iter)
                    sum = iter->data + carry;
                else
                    sum = carry;
        
                digit = sum%10;
                carry = sum/10;
                
                // cout<<"sum:"<<sum<<endl;
                // cout<<"digit:"<<digit<<endl;
                
                ansIter->next = new Node(digit);
                
                if(iter)
                    iter = iter->next;
                    
                ansIter = ansIter->next;

            }
            
            return ansHead->next;
            
        }
        
    }
    
    Node* addOne(Node *head) 
    {
        //reverse the list
        Node* reversed = reverseList(head);
        
        //add one
        Node* added = add(reversed);
        
        //reverse the answer
        reversed = reverseList(added);
        
        return reversed;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends