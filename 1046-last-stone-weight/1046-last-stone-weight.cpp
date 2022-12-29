class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> q;
        
        //elements inserted in queue
        
        for(int x:stones){
            q.push(x);
        }
        
        while(q.size()>1){
            
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            
            if(x!=y)q.push(x-y);
            
        }
        
        if(q.empty())return 0;
        else return q.top();
        
    }
};