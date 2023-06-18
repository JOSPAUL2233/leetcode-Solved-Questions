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
    
    ListNode* getMid(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        return slow;
        
    }
    
    //try making without dummy node
    ListNode* merge(ListNode* left,ListNode* right){
        
        //edge cases
        if(left == NULL)
            return right;
        
        if(right == NULL)
            return left;
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* iter = dummyHead;
        
        while(left != NULL && right != NULL){
            
            if(left->val < right->val){
                
                iter->next = left;
                left = left->next;
                
            }else{
                
                iter->next = right;
                right = right->next;
                
            }
         
            iter = iter->next;

        }
        
        if(left != NULL)
            iter->next = left;
           
        if(right != NULL)
            iter->next = right;
        
        return dummyHead->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        //edge case
        if(head == NULL || head->next == NULL)
            return head;
        
        //getting middle node
        ListNode* mid = getMid(head);
        
        ListNode* left = head;
        ListNode* right = mid->next;
        
        mid->next = NULL;
        
        //recursion for splitting
        left = sortList(left);
        right = sortList(right);
        
        //merging
        ListNode* ans = merge(left,right);
        
        return ans;
        
    }
};