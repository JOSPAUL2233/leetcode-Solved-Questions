class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        
        //base case, when index goes out of range
        if(index == nums.size()){
            
            ans.push_back(nums);
            return;
            
        }
        
        //iterate through all the alphabets from current index till last index
        for(int i = index;i<nums.size();i++){
            
            swap(nums[index],nums[i]);//swap
            solve(nums,ans,index+1);//go for next index
            swap(nums[index],nums[i]);//backtracking
            
        }
         
    }
    
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int index = 0;
        
        solve(nums,ans,index);
        
        return ans;
        
    }
};