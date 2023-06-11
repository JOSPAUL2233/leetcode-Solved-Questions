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
    bool hasCycle(ListNode *head) {
        
        map<ListNode*,bool> visited;
        
        //edge case
        if(head==NULL)return false;
        
        ListNode* it = head->next;
        
        visited[head]=true;
        
        while(it != NULL){
            
            if(visited[it] == true){
                return true;
            }
            
            visited[it] = true;
            
            it = it->next;
        }
        
        return false;
        
    }
};