class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        map<int,bool> m;
        vector<int> ans;
        
        for(int i = 0;i<nums.size();i++){
            
            if(! m.count(nums[i])){
                
                m[nums[i]] = true;
                
            }else{
                
                ans.push_back(nums[i]);
                
            }
            
        }
        
        return ans;
        
    }
};