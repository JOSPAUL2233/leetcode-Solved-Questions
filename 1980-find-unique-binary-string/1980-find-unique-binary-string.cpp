class Solution {
public:
    
    void solve(int num, string path,vector<string> nums,string &ans){
        
        if(ans.size() != 0)
            return;
        
        //base case
        if(path.size() == num){
            
            //check if path is there in the 
            for(int i = 0;i<nums.size();i++){
                
                if(nums[i] == path)
                    return;
                
            }
            
            ans = path;
            return;
            
        }
        
        solve(num,path+'0',nums,ans);//recursive call
        
        solve(num,path+'1',nums,ans);//recursive call
        
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        string path = "";
        
        string ans = "";
        
        solve(nums[0].size(),path,nums,ans);
        
        return ans;
        
    }
};