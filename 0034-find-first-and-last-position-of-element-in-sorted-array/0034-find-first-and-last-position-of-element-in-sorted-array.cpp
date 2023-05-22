class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        int start = 0;
        int end = nums.size()-1;
        
        int first = -1;
        int second = -1;
        
        
        //searching first occurance
        
        while(start<=end){
            
            int mid = (start+end)/2;
            
                if(nums[mid]==target){
                    
                    first = mid;
                    end = mid-1;
                    
                }else if(nums[mid]<target){
                    
                    start = mid+1;
                    
                    
                }else{
                    
                    end = mid-1;
                    
                }
            
        }
        
        //incase the target was not found
        if(first==-1)return {-1,-1};
        
        //searching second occurance
        
        start = 0;
        end = nums.size()-1;
        
        while(start<=end){
            
            int mid = (start+end)/2;
            
                if(nums[mid]==target){
                    
                    second = mid;
                    start = mid+1;
                    
                }else if(nums[mid]<target){
                    
                    start = mid+1;
                    
                    
                }else{
                    
                    end = mid-1;
                    
                }
            
        }
        
    return {first,second};
        
        
    }
};