class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start = 0;
        int minLength = INT_MAX;
        int sum = 0;
        
        
        for(int i = 0;i<nums.size();i++){
            
            sum += nums[i];
            
            while(sum >= target){
                
                int length = i - start + 1;
                
                //store the smaller length
                minLength = minLength < length ? minLength : length;
                
                sum -= nums[start];
                start++;
                
            }
            
        }
        
        return minLength == INT_MAX ? 0 : minLength;
        
    }
};