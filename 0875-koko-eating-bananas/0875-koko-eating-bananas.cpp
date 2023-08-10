class Solution {
public:
    
    
    bool isPossible(vector<int>& piles,int h,int mid){
        
        long totalHours = 0;
        
        for(int i = 0;i<piles.size();i++){

            totalHours += ceil((double)piles[i]/mid);
            
        }
        
        if(totalHours <= h)
            return true;   
        else
            return false;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        //answer will lie between 1 and maxElement in array
        //UNDERSTAND THE INTUITION!!!
        
        int start = 1;
        int end = INT_MIN;
        
        //find the maximum element in piles
        for(int i = 0;i<piles.size();i++){
            
            end = max(end,piles[i]);
            
        }
        
        //go for binary search
        int ans = -1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(piles,h,mid)){
                                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
            
        }
        
        return ans;
        
    }
};