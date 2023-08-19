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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)
            return head;
        
        //store the even Head since we have to join the end of odd LL to head LL
        ListNode* evenHead = head->next;
        
        //create two pointers for odd and even
        ListNode* evenIter = head->next;
        ListNode* oddIter = head;
        
        while(oddIter->next != NULL && evenIter->next != NULL){
            
            //change the linkage of odd part
            oddIter -> next = evenIter -> next;
            oddIter = oddIter->next;
            
            //change the linkage of even part
            evenIter -> next = oddIter -> next;
            evenIter = evenIter -> next;
                        
        }
        
        //if the loop ended in odd index at the last, make it NULL
        if(evenIter != NULL){
            
            evenIter = NULL;
            
        }
        
        //join odd tail and even head
        
        oddIter -> next = evenHead;
        
        return head;
        
    }
};