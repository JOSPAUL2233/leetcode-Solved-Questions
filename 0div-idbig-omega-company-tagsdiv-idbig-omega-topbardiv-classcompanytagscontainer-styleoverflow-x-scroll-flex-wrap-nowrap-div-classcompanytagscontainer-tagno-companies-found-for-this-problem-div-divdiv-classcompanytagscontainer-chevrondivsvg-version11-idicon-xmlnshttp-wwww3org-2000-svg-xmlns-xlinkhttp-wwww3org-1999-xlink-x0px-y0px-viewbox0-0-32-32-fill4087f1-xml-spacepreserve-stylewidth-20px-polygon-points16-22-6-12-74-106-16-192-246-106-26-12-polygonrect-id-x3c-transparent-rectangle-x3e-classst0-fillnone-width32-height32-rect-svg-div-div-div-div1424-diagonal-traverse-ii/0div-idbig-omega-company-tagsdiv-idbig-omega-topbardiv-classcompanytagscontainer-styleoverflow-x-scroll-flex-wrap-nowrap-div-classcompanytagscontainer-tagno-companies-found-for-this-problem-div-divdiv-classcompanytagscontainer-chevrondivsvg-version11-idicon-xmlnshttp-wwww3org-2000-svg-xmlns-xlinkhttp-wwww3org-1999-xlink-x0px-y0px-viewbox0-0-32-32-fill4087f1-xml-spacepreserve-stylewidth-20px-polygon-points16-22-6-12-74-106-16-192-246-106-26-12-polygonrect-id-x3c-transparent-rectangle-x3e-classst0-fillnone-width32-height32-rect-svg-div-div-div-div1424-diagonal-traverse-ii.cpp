class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        
        int maxDiaSum = 0;
        
        for(int i = nums.size()-1;i>=0;i--){
            
            for(int j = nums[i].size()-1;j>=0;j--){
                
                int diaSum = i+j;
                mp[diaSum].push_back(nums[i][j]);
                maxDiaSum = max(maxDiaSum,diaSum);
                
            }
            
        }
        
        for(int i = 0;i<=maxDiaSum;i++){
            
            for(int ele : mp[i]){//map[i] is a vector and ele is the individual elements in that vector
                
                ans.push_back(ele);
                
            }
            
        }
        
        return ans;
        
    }
};