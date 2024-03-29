//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    
    void insertAtTail(Node* &tail,Node* iter){
        
        tail->next = iter;
        tail = iter;
        
    }
    
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        
        //make three dummy seperate nodes as the 1st node
        //for 0s,1s and 2s inorder to create three different
        //linked lists
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* iter = head;
        
        //allocate seperately for each of them
        
        while(iter != NULL){
            
            int value = iter->data;
            
            if(value == 0){
                
                insertAtTail(zeroTail,iter);
                
            }else if(value == 1){
                
                insertAtTail(oneTail,iter);
                
            }else{
                
                insertAtTail(twoTail,iter);
            }
            
            iter = iter->next;
            
        }
        
        //merge all three linked list
        
        //1s is not empty
        if(oneHead->next != NULL){
            
            zeroTail->next = oneHead->next;
        
        //1s is empty
        }else{
            
            zeroTail -> next = twoHead->next;
            
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        Node* newHead = zeroHead->next;
        
        // //delete the dummy nodes
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return newHead;

    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends