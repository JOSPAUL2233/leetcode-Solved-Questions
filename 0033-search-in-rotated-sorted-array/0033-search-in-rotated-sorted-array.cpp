class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            
            
            int mid = low + (high - low)/2;
            
            
            //check if target is found
            if(nums[mid] == target)
                return mid;
            
            //if left part is sorted
            if(nums[low] <= nums[mid]){
                
                //check if element exists in the left part,
                //if yes, then search in the left part
                if(target >=nums[low] && target <= nums[mid]){
                    
                    high = mid-1;
                    
                }else{
                    
                    low = mid+1;
                    
                }
                
            //if right part is sorted
            }else{
                
                //check if element exists in the right part,
                //if yes, then search in the right part
                if(target >=nums[mid] && target <= nums[high]){
                    
                    low = mid+1;
                    
                }else{
                    
                    high = mid-1;
                    
                }
                
            }
            
        }
        
        //if the element was not found
        return -1; 
    }
};