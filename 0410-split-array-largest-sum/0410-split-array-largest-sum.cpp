class Solution {
public:
    
    bool isPossible(vector<int> nums,int k,int mid){
        
        int count = 1;
        int sum = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i] + sum > mid){
                
                count++;
                sum = nums[i];
                
                if(count > k)
                    return false;
                
            }else{
                
                sum += nums[i];
                
            }
            
        }
        
        return true;
        
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        
        //SAME LIKE BOOK ALLOCATION--------
        
        //answer lies between max element and sum of all the elements
        int n = nums.size();
        
        int start = INT_MIN;
        int end = 0;
        
        for(int i = 0;i<n;i++){
            
            if(nums[i] > start)
                start = nums[i];
            
            end += nums[i];
            
        }
        
        //binary search
        int ans = -1;
        
        while(start <= end){
            
            int mid = start + ( end - start )/2;
            
            if(isPossible(nums,k,mid)){
                
                ans = mid;
                end = mid-1;
                
            }else{
                
                start = mid+1;
                
            }
            
        }
        
        return ans;
        
    }
};