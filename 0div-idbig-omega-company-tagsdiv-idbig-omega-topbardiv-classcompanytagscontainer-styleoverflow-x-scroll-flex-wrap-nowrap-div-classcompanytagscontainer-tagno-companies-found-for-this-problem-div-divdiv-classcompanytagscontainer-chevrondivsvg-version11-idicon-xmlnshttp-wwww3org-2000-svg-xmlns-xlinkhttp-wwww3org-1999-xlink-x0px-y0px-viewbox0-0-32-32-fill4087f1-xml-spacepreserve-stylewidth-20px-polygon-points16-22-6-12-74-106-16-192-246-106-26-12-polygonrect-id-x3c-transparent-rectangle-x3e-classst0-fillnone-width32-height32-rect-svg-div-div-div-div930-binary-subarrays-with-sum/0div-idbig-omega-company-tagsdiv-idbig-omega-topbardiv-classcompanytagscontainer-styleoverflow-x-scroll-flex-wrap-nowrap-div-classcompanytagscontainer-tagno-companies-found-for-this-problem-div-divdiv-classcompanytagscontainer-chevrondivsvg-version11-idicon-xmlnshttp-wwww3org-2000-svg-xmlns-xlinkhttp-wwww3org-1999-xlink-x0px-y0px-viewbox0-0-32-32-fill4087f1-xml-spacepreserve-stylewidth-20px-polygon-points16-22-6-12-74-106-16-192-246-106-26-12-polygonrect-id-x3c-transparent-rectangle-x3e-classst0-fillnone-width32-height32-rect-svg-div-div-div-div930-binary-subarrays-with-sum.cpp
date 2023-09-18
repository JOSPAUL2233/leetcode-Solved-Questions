class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int,int> prefixSum;//stores--> sum, count
        int sum = 0;
        int count = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            //keep on storing sum
            sum += nums[i];
            
            //check for equals condition
            if(sum == goal)
                count++;
                        
            //get the number after subtracting which we will get the sum as goal
            int rem = sum - goal;
            
            //find if that number if there
            if(prefixSum.find(rem) != prefixSum.end()){
                
                //if found,store the occurance of that number previously
                count += prefixSum[rem];
                
            }
            
            //increment the occurance of sum
            prefixSum[sum]++;

        }
        
        return count;
    }
};