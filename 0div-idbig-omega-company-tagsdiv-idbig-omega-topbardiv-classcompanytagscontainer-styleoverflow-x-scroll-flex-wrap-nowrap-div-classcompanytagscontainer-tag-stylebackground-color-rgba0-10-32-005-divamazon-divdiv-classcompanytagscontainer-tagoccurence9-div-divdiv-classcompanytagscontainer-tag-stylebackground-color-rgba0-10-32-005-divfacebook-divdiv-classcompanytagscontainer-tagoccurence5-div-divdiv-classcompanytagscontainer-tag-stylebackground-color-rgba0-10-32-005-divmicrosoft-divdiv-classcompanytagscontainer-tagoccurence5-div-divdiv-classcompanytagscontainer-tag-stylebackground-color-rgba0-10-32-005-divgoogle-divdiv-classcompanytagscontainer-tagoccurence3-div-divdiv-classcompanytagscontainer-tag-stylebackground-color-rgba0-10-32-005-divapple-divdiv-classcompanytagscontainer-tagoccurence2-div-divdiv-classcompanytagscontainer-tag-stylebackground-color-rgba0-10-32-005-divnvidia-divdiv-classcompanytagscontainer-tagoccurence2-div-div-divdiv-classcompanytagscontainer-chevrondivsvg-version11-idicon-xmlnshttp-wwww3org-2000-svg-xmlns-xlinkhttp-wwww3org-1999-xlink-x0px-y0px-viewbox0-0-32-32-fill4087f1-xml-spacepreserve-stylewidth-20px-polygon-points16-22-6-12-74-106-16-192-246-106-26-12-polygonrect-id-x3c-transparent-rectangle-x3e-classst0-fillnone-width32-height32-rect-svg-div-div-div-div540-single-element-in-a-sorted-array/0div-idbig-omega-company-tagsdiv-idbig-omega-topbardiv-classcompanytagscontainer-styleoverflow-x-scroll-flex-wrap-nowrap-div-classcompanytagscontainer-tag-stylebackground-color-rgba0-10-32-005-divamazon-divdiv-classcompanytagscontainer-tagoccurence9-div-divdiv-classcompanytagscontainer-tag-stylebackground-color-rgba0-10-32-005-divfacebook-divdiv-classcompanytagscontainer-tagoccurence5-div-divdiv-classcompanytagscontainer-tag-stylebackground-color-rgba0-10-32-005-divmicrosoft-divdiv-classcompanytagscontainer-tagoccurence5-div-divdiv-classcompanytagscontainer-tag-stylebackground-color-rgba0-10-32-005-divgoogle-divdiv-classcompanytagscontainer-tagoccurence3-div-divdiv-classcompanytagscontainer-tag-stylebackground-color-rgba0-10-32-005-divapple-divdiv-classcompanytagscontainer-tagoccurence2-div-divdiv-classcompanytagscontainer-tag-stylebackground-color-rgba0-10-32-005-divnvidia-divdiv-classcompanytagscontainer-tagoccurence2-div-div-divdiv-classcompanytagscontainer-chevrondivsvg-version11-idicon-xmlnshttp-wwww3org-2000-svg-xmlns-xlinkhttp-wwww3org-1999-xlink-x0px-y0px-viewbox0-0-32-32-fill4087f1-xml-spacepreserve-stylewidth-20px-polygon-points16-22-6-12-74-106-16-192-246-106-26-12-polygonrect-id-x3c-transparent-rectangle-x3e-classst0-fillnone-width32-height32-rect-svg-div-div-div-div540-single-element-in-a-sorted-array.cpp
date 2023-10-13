class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        //edge cases
        if(nums.size() == 1)
            return nums[0];
        
        if(nums[0] != nums[1])
            return nums[0];
        
        if(nums[nums.size()-1] != nums[nums.size()-2])
            return nums[nums.size()-1];
        
        //shorten the search space and search in this space
        int start = 1;
        int end = nums.size()-2;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            //check for single
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            else if(mid%2 == 0){
                
                if(nums[mid] == nums[mid+1])
                    start = mid+1;
                else
                    end = mid-1;
                
            }else{
                
                if(nums[mid] == nums[mid+1])
                    end = mid-1;
                else
                    start = mid+1;
                
            }
            
        }
        
        return -1;
        
    }
};