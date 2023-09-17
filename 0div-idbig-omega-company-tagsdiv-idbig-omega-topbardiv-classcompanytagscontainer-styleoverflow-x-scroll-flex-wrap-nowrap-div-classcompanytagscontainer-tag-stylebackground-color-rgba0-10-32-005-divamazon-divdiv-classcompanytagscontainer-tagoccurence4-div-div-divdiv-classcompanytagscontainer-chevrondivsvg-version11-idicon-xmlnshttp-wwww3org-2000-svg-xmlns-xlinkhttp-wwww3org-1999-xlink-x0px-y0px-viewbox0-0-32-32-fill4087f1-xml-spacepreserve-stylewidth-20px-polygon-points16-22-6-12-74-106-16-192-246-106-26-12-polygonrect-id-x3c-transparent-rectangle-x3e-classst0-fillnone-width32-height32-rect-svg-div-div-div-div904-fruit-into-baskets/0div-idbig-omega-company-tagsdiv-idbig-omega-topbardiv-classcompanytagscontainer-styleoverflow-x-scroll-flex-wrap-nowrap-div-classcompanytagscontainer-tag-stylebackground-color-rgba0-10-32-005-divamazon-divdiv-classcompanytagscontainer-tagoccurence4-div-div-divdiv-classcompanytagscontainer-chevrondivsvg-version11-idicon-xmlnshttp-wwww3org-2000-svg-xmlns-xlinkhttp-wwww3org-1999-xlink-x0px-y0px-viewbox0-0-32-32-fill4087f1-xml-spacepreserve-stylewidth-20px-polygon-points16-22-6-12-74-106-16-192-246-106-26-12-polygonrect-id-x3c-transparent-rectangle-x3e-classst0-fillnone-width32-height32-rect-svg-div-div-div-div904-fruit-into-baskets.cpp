class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        map<int,int> basket;//stores fruitType,fruitCount
        
        int maxCount = INT_MIN;
        int left = 0;
        
        for(int right = 0;right < fruits.size();right++){
            
            //put the fruit in the basket
            basket[fruits[right]]++;
            
            //shrintk the basket size from left if the basket is overflowing
            while(basket.size() > 2){
                
                //decrease count of left side fruit since we are
                //removing one by one
                basket[fruits[left]]--;
                
                //if fruit count becomes zero, remove it from basket
                if(basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                
                left++;
                
            }
            
            //calculate the number of fruits anc store the maximum
            int count = right - left + 1;
            maxCount = max(maxCount,count);
            
        }
        
        return maxCount;
        
    }
};