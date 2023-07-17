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
    void insertAtTail(ListNode* &ansHead,ListNode* &ansTail,int digit){
        
        //make a new node
        ListNode* temp = new ListNode(digit);
        
        //if answer is empty
        if(ansHead == NULL){
            
            ansHead = temp;
            ansTail = temp;
        
        //if answer is not empty
        }else{
            
            ansTail->next = temp;
            ansTail = temp;
            
        }
        
    }
    
    ListNode* addLists(ListNode* head1,ListNode* head2){
        
        int carry = 0;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(head1 != NULL || head2 != NULL || carry != 0){
            
            int val1 = 0;
            int val2 = 0;
            
            if(head1)
                val1 = head1->val;
            if(head2)
                val2 = head2->val;
                            
            int sum = val1 + val2 + carry;
            
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            if(head1 != NULL)
                head1 = head1 -> next;
            
            if(head2 != NULL)
                head2 = head2 -> next;
            
        }
        
        return ansHead;
    }
    
    ListNode* reverseList(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* iter = head;
        ListNode* next = NULL;
        
        while(iter != NULL){
            
            next = iter->next;
            iter->next = prev;
            
            prev = iter;
            iter = next;
        }
        
        return prev;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //step 1 - Reverse the given lists
        ListNode* head1 = reverseList(l1);
        ListNode* head2 = reverseList(l2);
                
        //step 2 - do addition of two lists
        ListNode* ans = addLists(head1,head2);
                
        //step 3 - Reverse the answer
        ans = reverseList(ans);
        
        return ans;
        
    }
};