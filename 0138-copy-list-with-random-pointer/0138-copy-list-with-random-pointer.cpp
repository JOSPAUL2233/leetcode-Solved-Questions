/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //construct deep copies of nodes
        map<Node*,Node*> copy;
        Node* iter = head;
        
        while(iter != NULL){ 
            //creating new node
            Node* temp = new Node(iter->val);
            
            //mapping original node to the deep copy
            copy[iter] = temp;
            
            iter = iter->next;
        }
        
        //take care of next and random pointer
        
        iter = head;
        
        while(iter != NULL){
            
            //next pointer
            copy[iter] -> next = copy[iter->next];
            
            //random pointer
            copy[iter] -> random = copy[iter->random];
            
            iter = iter->next;
            
        }
        
        return copy[head];
        
    }
};