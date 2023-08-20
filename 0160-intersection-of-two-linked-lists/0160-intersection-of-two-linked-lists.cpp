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
        
        //count the number of nodes in each linked list
        
        int countA = 0;
        int countB = 0;
        
        ListNode* iterA = headA;
        ListNode* iterB = headB;
        
        //count number of nodes in first list
        while(iterA != NULL){
            
            countA++;
            iterA = iterA -> next;
            
        }
     
        //count number of nodes in second list
        while(iterB != NULL){
            
            countB++;
            iterB = iterB -> next;
            
        }
        
        //find the difference and adjust the position of pointers
        int diff = abs(countA - countB);
        
        iterA = headA;
        iterB = headB;
        
        if(countA > countB){
            
            //shift first to diff times forward
            while(diff > 0){
                
                iterA = iterA -> next;
                diff--;
                
            }
            
        }else{
            
            //shift second to diff times forward
            while(diff > 0){
                
                iterB = iterB -> next;
                diff--;
                
            }
            
        }
        
        
        
        //now, move both the pointers one by one forward and check for intersection
        while(iterA != NULL){
            
            //if intersection happens
            if(iterA == iterB)
                return iterA;
            
            iterA = iterA->next;
            iterB = iterB->next;
            
        }
        
        //no intersection
        return NULL;
        
    }
};