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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //apprach 1 --> using hashmap (using space)
        
        //approach 2 --> Using two pointers
        
        //count the number of nodes in each linked list
        int count1 = 0;
        int count2 = 0;
        
        ListNode* iter = headA;
        
        while(iter){
            count1++;
            iter = iter->next;
        }
        
        iter = headB;
        
        while(iter){
            count2++;
            iter = iter->next;
        }
        
        int diff = abs(count1 - count2);
        
        //move the head of larger linked list forward diff times
        
        ListNode* iter1;
        ListNode* iter2;
        
        if(count1>count2){
            iter1 = headA;
            iter2 = headB;
            
        }else{
            iter1 = headB;
            iter2 = headA;
        }
        
        for(int i = 0;i<diff;i++){
            
            iter1 = iter1->next;
            
        }
        
        //move forward one by one
        while(iter1){
            
            if(iter1 == iter2)
                return iter1;
            
            iter1 = iter1->next;
            iter2 = iter2->next;
            
        }
        
        return NULL;
        
    }
};