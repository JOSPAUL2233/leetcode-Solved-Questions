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
    
    void findLength(int &length,ListNode* head){
        
        if(head==NULL)return;
        length++;
            findLength(length,head->next);
        
    }
    
    ListNode* middleNode(ListNode* head) {
        
        int length = 0;
        
        findLength(length,head);
        
        int count = 0;
        
        ListNode *temp = head;
        
        while(count!=(length/2)){
            count++;
            temp = temp->next;
        }
        
        return temp;
        
    }
};