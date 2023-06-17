//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        ListNode* prev = NULL;
        ListNode* iter = head;
        
        //edge case
        if(iter == NULL || iter->next == NULL)
            return iter;
        
        //go to last node
        while(iter->next != NULL){
            
            prev = iter;
            iter = iter->next;
            
        }
        
        //extract the value
        int val = iter->val;
        
        //deleting the last node
        prev->next = NULL;
        
        //making new node and attaching it to the begening of
        //the linked list
        ListNode* temp = new ListNode(val);
        temp->next = head;
        
        return temp;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ListNode*> a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=new ListNode(x);
            if(i!=0){
                a[i-1]->next=a[i];
            }
        }
        ListNode *head=a[0];
        Solution ob;
        head=ob.moveToFront(head);
        while(head!=NULL){
            cout<<head->val;
            if(head->next!=NULL){
                cout<<" ";
            }
            head=head->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends