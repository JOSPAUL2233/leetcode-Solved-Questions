class Solution {
public:
    
    bool isPossible(vector<int> weights,int days,int mid){
        
        //keep track of days
        int totalDays = 1;
        int totalWeight = 0;
        
        for(int i = 0;i<weights.size();i++){
                        
            //if the weights may excceed
            if(totalWeight + weights[i] > mid){
 
                //increment the day
                //and start counting weights from next iteration
                totalDays++;
                totalWeight = weights[i];
                
            }else{
                
                totalWeight += weights[i];
                
            }
            
        }

        
        //check if the totalDays exceeds the given days limit
        if(totalDays <= days)
            return true;
        else
            return false;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        //answer lies within max element and sum of all the elements(OBSERVATION)
                
        int start = INT_MIN;
        int end = 0;
        
        int ans = -1;
        
        //store the max value in start and sum in end
        for(int i = 0;i<weights.size();i++){
            
            if(weights[i] > start)
                start = weights[i];
            
            end += weights[i];
            
        }
        
        //do binary search
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(weights,days,mid)){
                
                //store the answer and find smaller value
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return ans; 
        
    }
};