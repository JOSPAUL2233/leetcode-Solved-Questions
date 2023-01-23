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
        
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        if((list1==NULL && list2==NULL)||(list1!=NULL && list2==NULL))return list1;
        
        if(list1==NULL && list2!=NULL)return list2;
        
        
        ListNode* merged = temp1;
        
        if(temp2->val < temp1->val){
            
            merged = temp2;
            temp2 = temp2->next;
            
        }
        else {
            
            temp1 = temp1->next;
            
        }
        
        ListNode* head = merged;
        
        while(temp1 != NULL && temp2 != NULL){
            
            if(temp2->val < temp1->val){
            
                merged->next = temp2;
                
                temp2 = temp2->next;
            
            }
            else {
            
                merged->next = temp1;
                
                temp1 = temp1->next;
            
            }
            
            merged = merged->next;
            
            
        }
        
        if(temp1 != NULL)merged -> next = temp1;
        else merged -> next = temp2;
        
        return head;
        
        
        
    }
};