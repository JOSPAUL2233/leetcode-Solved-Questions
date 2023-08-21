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
    
    int getLength(ListNode* iter){
        
        
        int count = 0;
        
        while(iter != NULL){
            
            count++;
            iter = iter->next;
            
        }
        
        return count;
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        //find the length of the list
        int length = getLength(head);
        
        if(length == 0)
            return head;
        
        //reduce the number of repeated rotation
        k = k % length;
        
        //edge case
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        //move fast pointer k times forward
        for(int i = 0;i<k;i++)
            fast = fast -> next;
        
        //move both pointers one by one forward until fast reaches at the end
        while(fast -> next != NULL){
            
            slow = slow->next;
            fast = fast->next;
            
        }
        
        //store the new head and adjust the links accordingly
        ListNode* newHead = slow->next;
        slow->next = NULL;
        
        fast->next = head;
        
        return newHead;
        
    }
};