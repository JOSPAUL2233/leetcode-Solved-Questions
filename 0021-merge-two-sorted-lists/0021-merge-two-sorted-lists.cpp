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
        
        ListNode* iter = NULL;
        ListNode* prev = NULL;
        ListNode* keep = NULL;
        
        ListNode* newHead = NULL;
        
        //assign smaller value to iter
        if(list1->val < list2->val){
            
            iter = list1;
            keep = list2;
            
        }else{
            
            iter = list2;
            keep = list1;
            
        }
        
        newHead = iter;
        
        //follow the algorithm---
        
        while(iter != NULL){
            
            //move iter to the right until it reaches a node which is larger than            
            //which is larger than the keep 
            while((iter != NULL && keep != NULL) && iter->val <= keep->val){
                
                prev = iter;
                iter = iter->next;
                
            }
            
            // cout<<"iter->val:"<< iter->val <<endl;
            //connect the link and swap(iter,keep)
            prev->next = keep;
            
            if(iter != NULL)
                swap(iter,keep);
            
        }
                
        return newHead;
        
    }
};