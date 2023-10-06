class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        //sort the cost
        sort(cost.begin(),cost.end());
        
        //edge cases
        if(cost.size() == 1)
            return cost[0];
        else if(cost.size() == 2)
            return cost[0]+cost[1];
        
        int minCost = 0;
        
        int buy1 = cost.size()-2;
        int buy2 = cost.size()-1;
        
        while(buy2 >= 0){
            
            minCost += cost[buy2];
            
            if(buy1 >= 0)
                minCost += cost[buy1];
            
            buy2 -= 3;
            buy1 -= 3;
            
        }
        
        return minCost;
        
    }
};