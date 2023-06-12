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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* iter = head;
        
        while(iter != NULL){
            
            //if same elements
            if(iter->next != NULL && iter->val == iter->next->val){
                
                //direct the link to the next element rather than the same element
                iter->next = iter->next->next;
                
            }else{
                
                iter = iter->next;
                
            }
            
        }
        
        return head;
        
    }
};