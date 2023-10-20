/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        //edge case
        if(head == NULL || head->next == NULL)
            return NULL;
            
        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = NULL;
        
        //find the intersection point
        while(fast != NULL){
            
            slow = slow->next;
            fast = fast->next;
            
            if(fast)
                fast = fast->next;
            
            if(slow == fast){
                
                ptr2 = slow;
                break;
                
            }            
        }
        
        if(ptr2 == NULL)
            return NULL;
        
        while(ptr1 != ptr2){
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
        }
        
        return ptr1;
        
    }
};