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
    ListNode* reverseKGroup(ListNode* head, int k) {   
        
        if(head == NULL)
            return NULL;
        
        //check if the remaining nodes are lesser than k
        
        ListNode* temp = head;
        for(int i = 0;i<k;i++){
            
            if(temp == NULL)
                return head;
            
            temp = temp->next;
            
        }
        
        //iteratively reverse the k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        for(int i = 0;i<k;i++){
            
            next = curr->next;
            
            curr -> next = prev;
            
            prev = curr;
            curr = next;
                        
        }
        
        //call recursion for the rest of the nodes
        head->next = reverseKGroup(next,k);
        
        //return prev as it stores the current head
        return prev;
        
    }
};