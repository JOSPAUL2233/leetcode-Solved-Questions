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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head)return NULL;
        
        if(!head->next)return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        while(first && second){
            
            //----SWAP----
            
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
            
            if(!first->next || !second->next)break;
            
            if(first->next->next && second->next->next){
                first = first->next->next;
                second = second->next->next;
            }else{
                break;
            }
        }
        
        return head;
        
    }
};