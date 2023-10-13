class Solution {
public:
    int mySqrt(int x) {
        
        int start = 1;
        int end = x;
        
        int ans = 0;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            //check for the answer
            long long sq = (long long)mid*mid;
            
            if(sq == x)
                return mid;
            
            if(sq > x){
                
                end = mid-1;
                
            }else{
                
                ans = mid;
                start = mid+1;
                
            }
            
        }
        
        return ans;
        
    }
};