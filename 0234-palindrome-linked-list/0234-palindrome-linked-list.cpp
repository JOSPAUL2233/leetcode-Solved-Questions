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
    
    ListNode* reverseList(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* iter = head;
        ListNode* next = NULL;
        
        while(iter != NULL){
            
            next = iter->next;
            iter->next = prev;
            
            //move one step forward
            prev = iter;
            iter = next;
        }
        
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        //reverse the second half
        ListNode* secondHead = reverseList(slow->next);
        slow->next = secondHead;
        
        //check for palindrome
        ListNode* left = head;
        ListNode* right = secondHead;
        
        while(right != NULL){
            
            if(left->val != right->val)
                return false;
            
            left = left->next;
            right = right->next;
            
        }
        
        return true;
        
    }
};