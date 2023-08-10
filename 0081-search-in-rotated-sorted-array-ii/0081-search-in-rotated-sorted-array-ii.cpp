class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            //if we got the target
            if(nums[mid] == target)
                return true;
            
            //check if low,mid and high elements are equal,if yes,
            //shrink the width and continue for next iteration
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                
                low++;
                high--;
                
                continue;
                
            }
            
            //if left part is sorted
            if(nums[low] <= nums[mid]){
                
                //check if target is in the left part,then search in left part
                //otherwise search in the right part
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
                
            }else{//if right part is sorted
                
                //check if target is in the right part,then search in right part
                //otherwise search in the left part
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
                
            }
            
        }
        
        return false;
    }
};