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
        
        int count = 0;
        
        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);
        
        ListNode* oddPart = oddHead;
        ListNode* evenPart = evenHead;
        
        //store in odd part and even part
        
        ListNode* iter = head;
        
        while(iter != NULL){
            
            if(count % 2 == 1){
                
                oddPart -> next = new ListNode(iter->val);
                oddPart = oddPart -> next;
                
            }else{
                
                evenPart -> next = new ListNode(iter->val);
                evenPart = evenPart -> next;
            }
            
            count++;
            iter = iter->next;
            
        }
        
        //attach both odd and even part
        
        evenPart -> next = oddHead -> next;
        
        return evenHead->next;
        
        
        
    }
};