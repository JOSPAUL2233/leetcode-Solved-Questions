//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:

    int getSize(Node* head){
        
        int count = 0;
        
        Node* iter = head;
        
        while(iter != NULL){
            
            count++;
            iter = iter->next;
            
        }
        
        return count;
        
    }

    int getNthFromLast(Node *head, int n)
    {
           
           //did not use recursion to find the size of the linked list sice
           //it was taking extra memory of call stack which gave sigmentation error
           int size = getSize(head);
           
           if(size  < n)
            return -1;
           
           int position = size - n;
           
           
           //move iter position times
           Node* iter = head;
           
           for(int i = 0;i<position;i++){
               
               iter = iter->next;
               
           }
           
           return iter->data;
           
    }
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends