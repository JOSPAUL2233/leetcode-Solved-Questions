/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* iter = head;
        
        while(iter != NULL){
            
            next = iter->next;
            iter->next = prev;
            
            prev = iter;
            iter = next;
            
            
        }
        
        return prev;
    }
    
    
    ListNode* deleteNode(ListNode* head,int position){
        
        ListNode* prev = NULL;
        ListNode* iter = head;
        
        int jumps = position-1;
        
        if(head==NULL || head->next == NULL)
            return NULL;
        
        if(jumps==0){
            
            head = head->next;
            return head;
            
        }
        
        while(jumps--){
            
            prev = iter;
            iter = iter->next;
            
        }
        
        prev->next = iter->next;
        
        delete(iter);
        
        return head;
        
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //reverse the list
        
        head = reverse(head);
        
        //delete node
        
        head = deleteNode(head,n);
        
        //reverse it back
        
        head = reverse(head);
        
        return head;
    }
};