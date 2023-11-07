class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0)
            return true;
        
        //edge case
        if(flowerbed.size() == 1)
            return flowerbed[0] == 0;
        
        int flowersPlanted = 0;
        
        //take care of first and last position
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            flowersPlanted++;
        }
        
        if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0){
            
            flowerbed[flowerbed.size()-1] = 1;
            flowersPlanted++;
            
        }
        for(int i = 1;i<flowerbed.size()-1;i++){
            
            //is safe
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0){
                
                flowerbed[i] = 1;
                flowersPlanted++;
                i++;
                
            }
            
        }
        
        if(flowersPlanted >= n)
            return true;
        else
            return false;
        
    }
};