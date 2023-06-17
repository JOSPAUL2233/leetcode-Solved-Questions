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
                
        //make  a structure in such a way that
        //copies are also linked with the original
        //linked list
        
        Node* next = NULL;
        Node* iter = head;
        
        while(iter != NULL){
            
            next = iter->next;
            
            //make deep copy node
            Node* temp = new Node(iter->val);
            
            //make new links
            iter->next = temp;
            temp->next = next;
          
            //move to next pointer in original list
            iter = next;
            
        }
        
        //take care of random pointers
        
        iter = head;
        
        while(iter != NULL){
            
            if(iter->random != NULL)
                iter->next->random = iter->random->next;
            
            iter = iter->next->next;
        }
                
        //seperate original linked listand deep copy linked list
        
        Node* copyHead = new Node(0);//this is a dummy node
        Node* copy = copyHead;
        iter = head;
        next = NULL;
        
        while(iter != NULL){
            
            next = iter->next->next;
            copy->next = iter->next;
            iter->next = next;
            
            copy = copy->next;
            iter = iter->next;
            
        }
        
        return copyHead->next;
        
    }
};