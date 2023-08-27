class Solution {
public:
    
    bool sumIsEqual(vector<int> arr,int n){
        
        //get the sum
        int sum = 0;
        for(int i = 0;i<arr.size();i++)
            sum += arr[i];
        
        //check if it is equal
        if(sum == n)
            return true;
        else
            return false;
        
    }
    
    void solve(vector<int> nums,int index,vector<int> path,vector<vector<int>> &ans,int k,int n){
        
        //base case
        if(path.size() == k){
            
            if(sumIsEqual(path,n)){
                
                ans.push_back(path);
                
            }
            
            return;
            
        }
        
        
        //loop throughout the nums
        for(int i = index;i<nums.size();i++){
            
            //there is no duplicates from 1 to 9, so we don't have to
            //take care of that case
            
            path.push_back(nums[i]);
            solve(nums,i+1,path,ans,k,n);
            path.pop_back();
                        
        }
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        
        int index = 0;
        
        vector<int> path;
        vector<vector<int>> ans;
        
        solve(nums,index,path,ans,k,n);
        
        return ans;
        
    }
};