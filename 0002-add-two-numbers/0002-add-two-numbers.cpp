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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        
        ListNode* ans = new ListNode();
        
        ListNode* head = ans;
        
        while(l1 && l2){
            
            int sum = l1->val + l2->val + carry;
            
            ans->next = new ListNode(sum%10);
                        
            carry = sum/10;
            
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
      
        }
        
        while(l1){
            int sum = l1->val + carry;
            ans->next = new ListNode(sum%10);
            carry = sum/10;
            
            l1 = l1->next;
            ans = ans->next;
            
        }
        
        while(l2){
            int sum = l2->val + carry;
            
            ans->next = new ListNode(sum%10);
            
            carry = sum/10;
            
            l2 = l2->next;
            ans = ans->next;
        }
        
        if(carry)ans->next = new ListNode(carry);
        
        return head->next;
        
        
    }
};