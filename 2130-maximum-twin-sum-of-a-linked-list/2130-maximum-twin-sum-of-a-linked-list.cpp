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
    
    void reverse(ListNode* &it2){
        
        ListNode* prev = NULL;
        ListNode* curr = it2;
        ListNode* forw = it2->next;
        
        while(curr != NULL){
            
            forw = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = forw;
            
        }
        
        it2 = prev;
        
        
    }
    int pairSum(ListNode* head) {
        
        //finding the mid
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            
            fast = fast->next->next;
            
        }
        
        
        
        ListNode* it1 = head;
        ListNode* it2 = slow->next;
        
        slow->next = NULL;
        
        reverse(it2);
        
        int sum = 0;
        
        while(it1!=NULL){
            
            int temp = it1->val + it2->val;
            if(temp>sum)sum=temp;
            
            
            it1 = it1->next;
            it2 = it2->next;
            
        }
        
        
        return sum;
    }
};