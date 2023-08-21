class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int start = 1;
        int end = num;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if((long)mid*mid == num)
                return true;
            
            if((long)mid*mid < num){
                
                start = mid+1;
                
            }else{
                
                end = mid-1;
                
            }
            
            
        }
        
        return false;
        
    }
};