class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<pair<int,int>> que;
        for(int i = 0;i<tickets.size();i++)
            que.push({tickets[i],i});
        
        int count = 0;
        
        while(!que.empty()){
            
            count++;
            
            auto p = que.front();
            que.pop();
            
            p.first--;
            if(p.first!=0)
                que.push({p.first,p.second});
            else if(p.second == k)
                return count;
            
        }
        
        return -1;
        
    }
};