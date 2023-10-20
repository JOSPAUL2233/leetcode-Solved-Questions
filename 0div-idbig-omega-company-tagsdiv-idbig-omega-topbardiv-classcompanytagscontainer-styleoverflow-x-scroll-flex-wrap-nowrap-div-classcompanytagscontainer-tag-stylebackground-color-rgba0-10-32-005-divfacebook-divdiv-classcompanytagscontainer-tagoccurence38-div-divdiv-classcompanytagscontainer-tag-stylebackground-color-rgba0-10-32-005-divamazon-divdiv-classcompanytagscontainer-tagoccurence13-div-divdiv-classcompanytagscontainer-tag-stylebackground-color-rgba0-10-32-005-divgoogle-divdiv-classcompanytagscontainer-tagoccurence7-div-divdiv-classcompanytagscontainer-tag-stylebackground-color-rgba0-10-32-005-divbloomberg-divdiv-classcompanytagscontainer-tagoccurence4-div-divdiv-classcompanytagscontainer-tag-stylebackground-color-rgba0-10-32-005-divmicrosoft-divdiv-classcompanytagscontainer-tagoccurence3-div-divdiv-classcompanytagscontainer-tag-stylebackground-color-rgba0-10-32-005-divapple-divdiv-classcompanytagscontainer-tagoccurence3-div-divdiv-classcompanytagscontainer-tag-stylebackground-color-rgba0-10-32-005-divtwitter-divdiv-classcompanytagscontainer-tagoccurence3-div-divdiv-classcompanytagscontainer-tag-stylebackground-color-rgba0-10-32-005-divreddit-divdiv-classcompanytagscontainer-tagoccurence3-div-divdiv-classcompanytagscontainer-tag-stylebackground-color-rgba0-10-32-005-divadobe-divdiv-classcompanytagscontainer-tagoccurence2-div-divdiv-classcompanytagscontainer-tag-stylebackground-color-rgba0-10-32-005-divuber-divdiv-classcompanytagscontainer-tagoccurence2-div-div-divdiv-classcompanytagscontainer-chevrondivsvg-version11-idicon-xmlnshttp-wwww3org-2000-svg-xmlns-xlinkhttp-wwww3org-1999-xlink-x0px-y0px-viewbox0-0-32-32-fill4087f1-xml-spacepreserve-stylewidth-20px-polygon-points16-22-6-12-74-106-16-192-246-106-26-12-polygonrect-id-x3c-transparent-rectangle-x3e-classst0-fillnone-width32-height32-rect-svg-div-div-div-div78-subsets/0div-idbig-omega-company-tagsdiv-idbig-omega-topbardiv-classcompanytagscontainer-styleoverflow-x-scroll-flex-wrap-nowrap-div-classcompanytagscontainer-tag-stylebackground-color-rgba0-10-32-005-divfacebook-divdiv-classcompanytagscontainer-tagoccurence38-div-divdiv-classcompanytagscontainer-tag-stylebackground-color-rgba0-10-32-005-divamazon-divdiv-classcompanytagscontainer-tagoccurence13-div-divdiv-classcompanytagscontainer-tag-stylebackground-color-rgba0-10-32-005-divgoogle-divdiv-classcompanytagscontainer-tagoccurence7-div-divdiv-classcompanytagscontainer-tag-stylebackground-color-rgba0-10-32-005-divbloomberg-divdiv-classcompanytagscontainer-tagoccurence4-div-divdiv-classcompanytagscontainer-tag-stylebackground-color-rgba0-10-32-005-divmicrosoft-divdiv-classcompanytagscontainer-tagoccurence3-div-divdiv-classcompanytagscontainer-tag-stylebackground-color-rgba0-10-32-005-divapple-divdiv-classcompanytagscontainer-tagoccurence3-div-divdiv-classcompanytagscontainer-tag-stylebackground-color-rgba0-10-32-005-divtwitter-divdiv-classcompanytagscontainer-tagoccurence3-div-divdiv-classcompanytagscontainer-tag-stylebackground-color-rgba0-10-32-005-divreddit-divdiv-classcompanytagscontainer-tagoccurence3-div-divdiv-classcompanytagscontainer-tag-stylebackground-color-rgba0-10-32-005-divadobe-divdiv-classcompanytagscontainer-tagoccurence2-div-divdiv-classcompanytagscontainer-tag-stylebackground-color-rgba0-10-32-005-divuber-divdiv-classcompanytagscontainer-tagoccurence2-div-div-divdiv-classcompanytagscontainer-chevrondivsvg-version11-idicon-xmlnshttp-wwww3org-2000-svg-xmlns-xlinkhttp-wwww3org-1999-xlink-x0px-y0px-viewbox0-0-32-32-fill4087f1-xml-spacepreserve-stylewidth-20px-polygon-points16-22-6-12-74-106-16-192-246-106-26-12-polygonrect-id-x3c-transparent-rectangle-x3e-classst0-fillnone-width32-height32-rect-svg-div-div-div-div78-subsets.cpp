class Solution {
public:
    
    void solve(vector<int> nums,vector<int> path,vector<vector<int>> &ans,int index){
        
        //base case
        if(index == nums.size()){
            
            ans.push_back(path);
            return;
            
        }
        
        //include and exclude
        solve(nums,path,ans,index+1);
        
        path.push_back(nums[index]);
        solve(nums,path,ans,index+1);
        
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int index = 0;
        
        vector<int> path;
        vector<vector<int>> ans;
        
        solve(nums,path,ans,index);
        
        return ans;
        
    }
};