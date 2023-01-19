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
    
    void solve(vector<int> &vec,ListNode* head){
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        vector<int> vec;
        
        solve(vec,head);
        
        for(int i = 0;i<vec.size()/2;i++){
         
            if(vec[i]!=vec[vec.size()-1-i])return false;
            
        }
        
        return true;
        
    }
};