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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        unordered_map<int,ListNode*> prefix;
        int sum = 0;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        prefix[0] = dummy;
        
        ListNode* iter = head;
        
        while(iter != NULL){
            
            sum += iter->val;
            
            if(prefix.find(sum) != prefix.end()){
                
                ListNode* start = prefix[sum];
                int ps = sum;
                
                //erase all the deleted nodes(virtually) from the map
                ListNode* it = start->next;
                
                while(it != iter){
                    
                    ps += it->val;
                    prefix.erase(ps);
                    
                    it = it->next;
                    
                }
                
                start->next = iter->next;
                
            }else{
                
                prefix[sum] = iter;
                
            }
            
            iter = iter->next;
            
        }
        
        return dummy->next;
        
    }
};