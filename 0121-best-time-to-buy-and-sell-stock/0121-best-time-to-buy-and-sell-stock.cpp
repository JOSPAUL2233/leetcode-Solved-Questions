class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //minimum price to left side
        int minPrice = prices[0];
        
        int maxProfit = 0;
        
        for(int i = 1;i<prices.size();i++){
            
            //calculate the current profit
            int profit = prices[i] - minPrice;
            
            //store the maximum profit
            maxProfit = max(maxProfit,profit);
            
            //update the minPrice value
            if(prices[i] < minPrice)
                minPrice = prices[i];
            
        }
        
        return maxProfit;
    }
};