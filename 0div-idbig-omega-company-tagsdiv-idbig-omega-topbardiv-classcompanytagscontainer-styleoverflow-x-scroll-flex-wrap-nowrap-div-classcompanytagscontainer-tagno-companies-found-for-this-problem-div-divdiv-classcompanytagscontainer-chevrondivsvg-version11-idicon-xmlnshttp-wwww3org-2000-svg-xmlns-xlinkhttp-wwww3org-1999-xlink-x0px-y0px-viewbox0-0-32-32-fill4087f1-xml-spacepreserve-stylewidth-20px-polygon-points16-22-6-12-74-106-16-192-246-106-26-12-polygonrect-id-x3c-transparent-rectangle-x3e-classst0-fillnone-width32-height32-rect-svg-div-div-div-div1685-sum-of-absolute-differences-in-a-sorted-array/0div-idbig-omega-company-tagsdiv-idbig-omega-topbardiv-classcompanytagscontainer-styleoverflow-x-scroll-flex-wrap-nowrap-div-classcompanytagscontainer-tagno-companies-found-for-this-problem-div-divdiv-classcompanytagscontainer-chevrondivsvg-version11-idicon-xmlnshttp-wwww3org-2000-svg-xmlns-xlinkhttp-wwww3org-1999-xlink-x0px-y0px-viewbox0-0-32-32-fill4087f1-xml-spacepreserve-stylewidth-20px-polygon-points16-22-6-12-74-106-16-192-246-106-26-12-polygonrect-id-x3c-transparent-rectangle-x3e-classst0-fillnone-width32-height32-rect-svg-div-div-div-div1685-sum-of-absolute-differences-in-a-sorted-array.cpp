class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        
        //maintain a prefixSum and totalSum variable and from which we can also calculate suffixSum lateron
                
        int totalSum = 0;
        
        for(int i : nums) totalSum += i;
        
        //now, computer the answer seperately using prefix and suffix sum
        
        vector<int> ans(n,-1);
        int prefixSum = 0;

        for(int i = 0;i<nums.size();i++){
            
            int leftCount = i;//number of elements present left side of ith position
            int rightCount = n-i;//number of elements present right side of ith position including the ith element
            int suffixSum = totalSum - prefixSum;
            
            ans[i] = ((nums[i] * leftCount) - prefixSum) + (suffixSum - ( nums[i] * rightCount));            
            prefixSum += nums[i];
            
        }
        
        return ans;
        
    }
};