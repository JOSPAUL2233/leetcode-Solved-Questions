class Solution {
public:
    bool isPossible(vector<int> bloomDay,int m,int k,int mid){
        
        int bouquets = 0;
        int flowers = 0;
        
        for(int i = 0;i<bloomDay.size();i++){
            
            if(bloomDay[i] <= mid){
                
                flowers++;
                if(flowers == k){
                    
                    flowers = 0;
                    bouquets++;
                    
                }
                
            }else{
                flowers = 0;
            }
            
        }
        
        if(bouquets >= m)
            return true;
        else
            return false;
        
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        //answer will lie between minElement and maxElement in bloomDay array
        
        int start = INT_MAX;
        int end = INT_MIN;
        
        //find the max and min element in the array
        
        for(int i = 0;i<bloomDay.size();i++){
            
            if(bloomDay[i] < start)
                start = bloomDay[i];
            
            if(bloomDay[i] > end)
                end = bloomDay[i];
            
        }
        
        int ans = -1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(bloomDay,m,k,mid)){
                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return ans;
        
    }
};