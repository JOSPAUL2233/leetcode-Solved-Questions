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
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        while(fast != NULL){
            
            //one step
            slow = slow->next;
            
            //two step
            fast = fast->next;
            if(fast)
                fast = fast -> next;
            
            if(slow == fast){
                
                ptr2 = slow;
                break;
                
            }
            
            
        }
        
        //if there is no loop
        if(fast == NULL)
            return NULL;
        
        while(ptr1 != ptr2){
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
        }
        
        return ptr1;
                
    }
};