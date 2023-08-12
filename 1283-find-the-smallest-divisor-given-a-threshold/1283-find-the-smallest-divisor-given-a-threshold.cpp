class Solution {
public:
    
    bool isPossible(vector<int> nums,int threshold,int mid){
        
        int sum = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            sum += ceil((double)nums[i]/mid);
            
            if(sum > threshold)
                return false;
        }
        
        return true;
        
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        //answer lies between 1 and maxElement in the array
        
        int start = 1;
        int end = INT_MIN;
        
        //find the maxValue
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i] > end)
                end = nums[i];
            
        }
        
        int ans = -1;
        
        //do binary search
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if(isPossible(nums,threshold,mid)){
                
                //store the answer and search for smaller value
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return ans;
        
    }
};