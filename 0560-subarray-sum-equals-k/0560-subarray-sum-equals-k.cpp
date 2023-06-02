class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> prefixSums;
        
        int sum = 0;
        int counter = 0;
        
        prefixSums[sum]++;
        
        for(int i = 0;i<nums.size();i++){
            
            sum += nums[i];
            
            int rem = sum - k;
        
            
            if(prefixSums.find(rem) != prefixSums.end()){
                
                counter = counter + prefixSums[rem];
                
            }
            
            prefixSums[sum]++;
            
        }
        
        return counter;
        
    }
};