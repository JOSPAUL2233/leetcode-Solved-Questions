class Solution {
    
    
public:
    
    void solve(vector<int> nums,vector<int> total,vector<vector<int>>& ans,int index){
        
        if(index==nums.size()){
            
            ans.push_back(total);
            return;
            
        }
        
        //exclude
        solve(nums,total,ans,index+1);
    
        
        //include
        total.push_back(nums[index]);
        solve(nums,total,ans,index+1);
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> total;
        int index = 0;
        
        solve(nums,total,ans,index);
        
        return ans;
        
        
    }
};