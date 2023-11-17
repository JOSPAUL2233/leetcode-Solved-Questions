class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int mini = INT_MIN;
        
        for(int i = 0;i<nums.size()/2;i++){
            
            int sum = nums[i] + nums[nums.size() -1 -i];
            
            mini = max(mini,sum);
            
        }
        
        return mini;
        
    }
};