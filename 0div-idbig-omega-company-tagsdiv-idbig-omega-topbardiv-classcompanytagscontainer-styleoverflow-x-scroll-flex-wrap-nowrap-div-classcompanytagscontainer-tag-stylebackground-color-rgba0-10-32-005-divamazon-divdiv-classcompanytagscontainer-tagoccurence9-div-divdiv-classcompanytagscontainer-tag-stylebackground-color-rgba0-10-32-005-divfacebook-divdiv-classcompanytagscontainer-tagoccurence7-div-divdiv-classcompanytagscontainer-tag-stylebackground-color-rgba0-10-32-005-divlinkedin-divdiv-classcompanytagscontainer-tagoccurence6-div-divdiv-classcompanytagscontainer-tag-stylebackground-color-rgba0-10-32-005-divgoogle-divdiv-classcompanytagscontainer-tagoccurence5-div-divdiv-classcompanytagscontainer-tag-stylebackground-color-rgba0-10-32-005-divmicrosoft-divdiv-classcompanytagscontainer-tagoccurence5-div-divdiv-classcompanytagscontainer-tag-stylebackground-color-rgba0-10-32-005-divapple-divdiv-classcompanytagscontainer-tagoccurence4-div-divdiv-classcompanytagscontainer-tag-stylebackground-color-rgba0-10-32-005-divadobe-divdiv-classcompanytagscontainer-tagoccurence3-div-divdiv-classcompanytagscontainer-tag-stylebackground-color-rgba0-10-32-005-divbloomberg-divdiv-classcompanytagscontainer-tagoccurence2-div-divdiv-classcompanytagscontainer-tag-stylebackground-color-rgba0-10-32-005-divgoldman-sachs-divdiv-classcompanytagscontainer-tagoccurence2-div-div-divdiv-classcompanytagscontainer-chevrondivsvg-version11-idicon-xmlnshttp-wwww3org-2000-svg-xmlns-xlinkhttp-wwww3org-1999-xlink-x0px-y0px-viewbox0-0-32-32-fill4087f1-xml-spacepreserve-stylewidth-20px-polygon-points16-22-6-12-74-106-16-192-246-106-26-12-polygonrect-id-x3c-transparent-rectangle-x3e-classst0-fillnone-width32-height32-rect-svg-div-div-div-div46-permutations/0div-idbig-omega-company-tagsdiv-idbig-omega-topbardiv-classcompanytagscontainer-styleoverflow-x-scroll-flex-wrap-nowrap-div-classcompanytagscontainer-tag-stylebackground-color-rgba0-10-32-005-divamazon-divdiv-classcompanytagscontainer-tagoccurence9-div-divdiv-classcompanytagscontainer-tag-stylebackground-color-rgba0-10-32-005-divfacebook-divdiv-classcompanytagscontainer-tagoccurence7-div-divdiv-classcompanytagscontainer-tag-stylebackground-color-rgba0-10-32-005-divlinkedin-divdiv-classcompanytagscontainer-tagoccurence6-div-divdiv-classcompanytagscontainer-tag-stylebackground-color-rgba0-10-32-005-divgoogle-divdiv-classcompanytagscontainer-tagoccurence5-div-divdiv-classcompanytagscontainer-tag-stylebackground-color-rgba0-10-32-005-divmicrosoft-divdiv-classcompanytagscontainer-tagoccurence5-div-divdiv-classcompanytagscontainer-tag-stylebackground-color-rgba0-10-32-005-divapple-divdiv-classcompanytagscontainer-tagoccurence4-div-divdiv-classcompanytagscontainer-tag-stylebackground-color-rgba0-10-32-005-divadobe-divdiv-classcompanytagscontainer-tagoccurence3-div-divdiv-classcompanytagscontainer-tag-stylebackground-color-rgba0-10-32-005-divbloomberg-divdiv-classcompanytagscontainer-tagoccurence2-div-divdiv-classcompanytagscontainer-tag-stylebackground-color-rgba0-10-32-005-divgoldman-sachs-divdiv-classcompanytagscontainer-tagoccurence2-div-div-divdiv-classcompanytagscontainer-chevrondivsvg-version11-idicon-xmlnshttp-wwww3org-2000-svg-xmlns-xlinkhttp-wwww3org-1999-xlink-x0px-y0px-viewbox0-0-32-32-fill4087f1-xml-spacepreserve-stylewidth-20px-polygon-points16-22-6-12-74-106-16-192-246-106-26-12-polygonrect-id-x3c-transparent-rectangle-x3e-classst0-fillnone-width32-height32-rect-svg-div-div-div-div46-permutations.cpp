class Solution {
public:
    
    void solve(int index,vector<int> nums,vector<int> path,vector<vector<int>> &ans,map<int,bool> visited){
        
        //base case,when the index goes out of range
        if(index == nums.size()){
            
            ans.push_back(path);
            return;
            
        }
        
        //run a loop for position placing
        for(int i = 0;i<nums.size();i++){
            
            if(!visited[i]){
                
                path.push_back(nums[i]);
                visited[i] = true;
                solve(index+1,nums,path,ans,visited);
                visited[i] = false;
                path.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> path;
        vector<vector<int>> ans;
        int index = 0;
        
        //keep a track of visited index
        map<int,bool> visited;
        
        solve(index,nums,path,ans,visited);
        
        return ans;
        
    }
};