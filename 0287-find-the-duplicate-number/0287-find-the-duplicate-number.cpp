class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int ans = 0;
        
        set<int> s;
        
        for(int i = 0;i<nums.size();i++){
            
            if(s.count(nums[i])){
                ans = nums[i];
                break;
            }else{
                s.insert(nums[i]);
            }
            
        }
        
        return ans;
        
    }
};