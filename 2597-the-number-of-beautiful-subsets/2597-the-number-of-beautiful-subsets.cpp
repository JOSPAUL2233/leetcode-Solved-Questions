class Solution {
public:
    
    void solve(vector<int> &nums,unordered_map<int,int> &mp,int ind,int k,int &ans){
        
        if(ind>=nums.size()){
            ans++;
            return;
        }
        
        //take out possible values that can make a diff of K with nums[i]
        int val1 = nums[ind]+k;
        int val2 = nums[ind]-k;
        
        //take
        if(mp[val1]==0 && mp[val2]==0){
            
            mp[nums[ind]]++;
            solve(nums,mp,ind+1,k,ans);
            mp[nums[ind]]--;
            
        }
        
        //not take
        solve(nums,mp,ind+1,k,ans);
        
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        int index = 0;
        int ans = 0;
        
        unordered_map<int,int> mp;
        
        solve(nums,mp,index,k,ans);
        
        return ans-1;
        
    }
};