class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> prefixSums;//(sum, number or occurances)
        
        int sum = 0;
        int counter = 0;
        
        //stores the prefixSum
        prefixSums[sum]++;
        
        for(int i = 0;i<nums.size();i++){
            
            sum += nums[i];
            
            //get the rem
            int rem = sum - k;
        
            //check if rem is already there in the prefixSum
            //if yes, then that means that a subarray is there with the calculated sum
            if(prefixSums.find(rem) != prefixSums.end()){
                
                counter = counter + prefixSums[rem];
                
            }
            
            //increment the occurance of the prefixSum
            //of the current sum
            prefixSums[sum]++;
            
        }
        
        return counter;
        
    }
};