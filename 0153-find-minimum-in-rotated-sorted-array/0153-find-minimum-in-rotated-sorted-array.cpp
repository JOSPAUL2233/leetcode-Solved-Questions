class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        
        int smaller = INT_MAX;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
                        
            //check if left side is sorted
            if(nums[low] <= nums[mid]){
                
                //store the smaller value
                smaller = min(smaller,nums[low]);
                
                //eliminate left and search in right
                low = mid+1;
                
                
            }else{
                                
                //store the smaller value
                smaller = min(smaller,nums[mid]);
                
                //eliminate the right and search in left
                high = mid-1;
                
            }
            
        }
        
        return smaller;
    }
};