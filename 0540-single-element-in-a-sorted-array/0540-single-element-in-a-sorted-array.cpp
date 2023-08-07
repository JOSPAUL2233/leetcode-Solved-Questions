class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //-----------------------------------------------
        //in the left side of the single element,
        //pair's index will be (even,odd)
        
        //but in the right side of the single element,
        //pair's index will be (odd,even)
        
        //use this property to identify left and right side
        //---------------------------------------------------
        
        int n = nums.size();
        
        //take care of edge cases
        if(n==1)
            return nums[0];
        
        if(nums[0] != nums[1])
            return nums[0];
        
        if(nums[n-1] != nums[n-2])
            return nums[n-1];
        
        //do binary search from index 1 to n-2
        
        int low = 1;
        int high = n-2;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            //if single element is found
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            
            //check for the elimination area
            if((mid % 2 == 1 && nums[mid] == nums[mid-1]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])){
                
                low = mid+1;
                
            }else{
                
                high = mid-1;
                
            }
            
        }
        
        return -1;
        
    }
};