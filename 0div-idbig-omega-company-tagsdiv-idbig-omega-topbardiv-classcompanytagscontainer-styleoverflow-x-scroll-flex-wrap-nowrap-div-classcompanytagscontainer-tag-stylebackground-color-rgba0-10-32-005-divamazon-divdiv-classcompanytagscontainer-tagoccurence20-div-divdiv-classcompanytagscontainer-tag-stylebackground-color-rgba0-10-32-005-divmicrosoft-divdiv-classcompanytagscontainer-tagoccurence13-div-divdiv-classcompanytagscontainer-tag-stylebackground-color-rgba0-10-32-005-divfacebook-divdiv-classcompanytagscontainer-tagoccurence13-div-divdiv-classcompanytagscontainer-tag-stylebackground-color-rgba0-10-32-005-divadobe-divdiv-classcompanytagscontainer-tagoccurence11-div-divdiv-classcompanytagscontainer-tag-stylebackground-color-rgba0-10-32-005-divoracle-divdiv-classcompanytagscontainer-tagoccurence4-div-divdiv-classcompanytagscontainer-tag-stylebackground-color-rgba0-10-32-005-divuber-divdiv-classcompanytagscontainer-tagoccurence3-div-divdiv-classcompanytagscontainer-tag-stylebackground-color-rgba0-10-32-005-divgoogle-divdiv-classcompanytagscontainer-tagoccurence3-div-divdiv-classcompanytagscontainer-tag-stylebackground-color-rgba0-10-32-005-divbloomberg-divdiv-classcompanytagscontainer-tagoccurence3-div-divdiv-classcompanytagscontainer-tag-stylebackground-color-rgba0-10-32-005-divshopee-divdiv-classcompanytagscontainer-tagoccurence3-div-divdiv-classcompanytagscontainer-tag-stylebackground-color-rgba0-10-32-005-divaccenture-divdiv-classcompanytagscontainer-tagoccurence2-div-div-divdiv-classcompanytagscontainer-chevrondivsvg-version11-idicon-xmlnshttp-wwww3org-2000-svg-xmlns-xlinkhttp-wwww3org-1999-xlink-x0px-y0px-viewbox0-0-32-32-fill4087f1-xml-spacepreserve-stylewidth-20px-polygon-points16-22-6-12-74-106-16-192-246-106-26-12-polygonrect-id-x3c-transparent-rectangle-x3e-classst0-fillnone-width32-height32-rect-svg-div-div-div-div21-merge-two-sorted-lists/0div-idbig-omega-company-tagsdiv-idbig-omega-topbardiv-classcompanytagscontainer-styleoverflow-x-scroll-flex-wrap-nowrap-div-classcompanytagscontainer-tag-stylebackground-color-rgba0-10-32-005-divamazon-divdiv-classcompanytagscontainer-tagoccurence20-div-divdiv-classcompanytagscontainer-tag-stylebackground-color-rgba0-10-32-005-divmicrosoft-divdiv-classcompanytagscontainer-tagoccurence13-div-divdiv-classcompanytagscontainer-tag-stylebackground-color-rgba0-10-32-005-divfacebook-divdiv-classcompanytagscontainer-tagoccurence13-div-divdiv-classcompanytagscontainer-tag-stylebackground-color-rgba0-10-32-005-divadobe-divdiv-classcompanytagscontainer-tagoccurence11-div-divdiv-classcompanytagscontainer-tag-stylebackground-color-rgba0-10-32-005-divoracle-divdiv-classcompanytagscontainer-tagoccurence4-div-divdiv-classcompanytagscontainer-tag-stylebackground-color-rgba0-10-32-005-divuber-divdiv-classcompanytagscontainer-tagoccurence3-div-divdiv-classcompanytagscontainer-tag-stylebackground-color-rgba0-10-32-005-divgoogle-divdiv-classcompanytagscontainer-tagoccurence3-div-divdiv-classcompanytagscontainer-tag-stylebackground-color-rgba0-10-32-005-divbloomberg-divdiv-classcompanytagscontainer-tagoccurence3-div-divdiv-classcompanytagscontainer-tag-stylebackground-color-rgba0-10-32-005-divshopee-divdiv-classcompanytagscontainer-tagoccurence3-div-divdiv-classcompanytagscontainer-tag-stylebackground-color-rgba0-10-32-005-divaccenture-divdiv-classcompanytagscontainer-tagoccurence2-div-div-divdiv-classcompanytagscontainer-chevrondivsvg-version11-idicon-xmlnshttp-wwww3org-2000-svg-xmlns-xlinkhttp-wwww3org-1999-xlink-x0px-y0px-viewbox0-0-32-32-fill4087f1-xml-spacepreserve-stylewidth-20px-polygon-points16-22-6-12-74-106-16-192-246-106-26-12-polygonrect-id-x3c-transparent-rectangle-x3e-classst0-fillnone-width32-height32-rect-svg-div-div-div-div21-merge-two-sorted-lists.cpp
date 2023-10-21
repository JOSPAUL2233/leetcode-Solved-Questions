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
        
        if(list1 == NULL)
            return list2;
        
        if(list2 == NULL)
            return list1;
        
        //declare pointers
        ListNode* iter = NULL;
        ListNode* keep = NULL;
        ListNode* prev = NULL;
        
        ListNode* head = NULL;
        
        //assign smaller node into iter and larger into keep
        if(list1->val <= list2->val){
            
            iter = list1;
            keep = list2;
            
        }else{
            
            iter = list2;
            keep = list1;
            
        }
        
        head = iter;
        
        //follow the algorithm
        while(iter && keep){
            
            
            while(iter && iter->val <= keep->val){
                
                prev = iter;
                iter = iter->next;
                
            }
            
            prev->next = keep;
                
            swap(iter,keep);
                        
        }
        
        // if(keep)
        //     prev->next = keep;
        
        return head;
        
    }
};