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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //edge cases
        if(list1 == NULL)
            return list2;
        
        if(list2 == NULL)
            return list1;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* iter = dummy;
        
        while(list1 && list2){
            
            if(list1->val < list2->val){
                
                iter->next = new ListNode(list1->val);
                list1 = list1->next;
                
            }else{
                
                iter->next = new ListNode(list2->val);
                list2 = list2->next;
                
            }
            
            iter = iter->next;
            
        }
        
        while(list1){
            
                iter->next = new ListNode(list1->val);
                list1 = list1->next;     
                iter = iter->next;
        }
        
        while(list2){
                iter->next = new ListNode(list2->val);
                list2 = list2->next;   
                iter = iter->next;
        }
        
        return dummy->next;
        
    }
};