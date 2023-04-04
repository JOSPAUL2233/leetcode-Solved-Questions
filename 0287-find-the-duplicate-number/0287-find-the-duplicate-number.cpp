class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int ans = 0;
        
        unordered_map<int,bool> visited;
        
        for(int i = 0;i<nums.size();i++){
            
            if(!visited[nums[i]]){
                
                visited[nums[i]] = true;
                
            }else{
                ans = nums[i];
                break;
            }
            
        }

        return ans;
        
    }
};