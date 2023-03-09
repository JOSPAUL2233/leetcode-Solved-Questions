class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        //outer loop for the 1st number
        
        for(int i = 0;i<n;i++){
            
            int t = -nums[i];
            
            int a = i+1;
            int b = n-1;
            
            while(a<b){
                
                int sum = nums[a]+nums[b];
                
                if(sum == t){
                    
                    ans.push_back({nums[a],nums[b],nums[i]});
                    
                    while(a<b && nums[a] == nums[a+1])a++;
                    while(a<b && nums[b] == nums[b-1])b--;
                    
                    a++;
                    b--;
                    
                    
                }else if(sum > t){
                    b--;
                    
                }else{
                    a++;                    
                }
                
                
            }
            
            while(i+1<n && nums[i] == nums[i+1])i++;
            
        }
        
        return ans;
        
    }
};