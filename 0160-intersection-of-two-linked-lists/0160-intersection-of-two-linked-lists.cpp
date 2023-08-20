/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        map<ListNode*,bool> visited;
        
        //iterate through first Linked List
        ListNode* iter = headA;
        while(iter != NULL){
            
            visited[iter] = true;
            
            iter = iter->next;
        }
        
        
        //iterate through second Linked List
        iter = headB;
        while(iter != NULL){
            
            if(visited[iter] == true)
                return iter;
            
            iter = iter->next;
            
        }
        
        //if there is no intersection found
        return NULL;
        
    }
};