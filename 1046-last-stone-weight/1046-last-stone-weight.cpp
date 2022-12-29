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
            
            if(x==y){
                continue;
            }else if(x<y){
                y = y-x;
                q.push(y);
            }else if(x>y){
                x = x-y;
                q.push(x);
            }
            
        }
        
        if(q.empty())return 0;
        else return q.top();
        
    }
};