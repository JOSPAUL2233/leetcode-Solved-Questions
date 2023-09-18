class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int,int> prefixSum;//stores--> sum, count
        int sum = 0;
        // prefixSum[sum]++;
        int count = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            sum += nums[i];
            
            if(sum == goal)
                count++;
                        
            int rem = sum - goal;
            
            if(prefixSum.find(rem) != prefixSum.end()){
                
                count += prefixSum[rem];
                
            }
            
            prefixSum[sum]++;

        }
        return count;
    }
};