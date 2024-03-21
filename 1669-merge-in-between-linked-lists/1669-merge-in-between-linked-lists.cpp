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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* iter1 = list1;
        ListNode* iter2 = iter1;
        
        a--;
        while(a--){
            
            iter1 = iter1->next;
            
        }
        
        b++;
        while(b--){
            
            iter2 = iter2->next;
            
        }
        
        ListNode* end = list2;
        ListNode* prev = NULL;
        
        while(end != NULL){
            
            prev = end;
            end = end->next;
            
        }
        
        iter1->next = list2;
        prev->next = iter2;
        
        return list1;
        
    }
};