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
    ListNode* removeElements(ListNode* head, int val) {
        
        
        
        while(head!=NULL && head->val == val){
            head = head->next;
        }
        
        
        ListNode* iter = head;
        
        
        while(iter!=NULL && iter->next!=NULL){
            
            if(iter->next->val==val){
                
                iter->next = iter->next->next;
                
            }else{
                iter = iter->next;
            }
        }
        
        return head;
        
    }
};