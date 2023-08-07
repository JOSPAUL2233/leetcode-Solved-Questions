class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        //using binary search-------------------------
        
        //take care of edge cases
        
        int n = nums.size();
        
        if(n == 1) return 0; // single element
        
		// check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        
        //there are three conditions to search in the remaining arrays -------------------------
        //1. mid element is the peak element
        //2. mid element is greater than prev element
        //3. mid element is lesser than prev element or lesser than next element and prev
        //   element
        
        int low = 1;
        int high = nums.size()-2;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;    
            
            //peak is found
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;

            //peak exists in the left part
            if(nums[mid] > nums[mid-1])
                low = mid+1;
            //peak exists in the right part
            else
                high = mid-1;
            
        }
        
        return -1;
        
    }
};