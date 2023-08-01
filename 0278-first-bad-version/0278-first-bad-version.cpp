// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 0;
        int end = n;
        
        int ans = -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(isBadVersion(mid)){
                
                //store the ans and find the left most answer
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return ans;
        
    }
};