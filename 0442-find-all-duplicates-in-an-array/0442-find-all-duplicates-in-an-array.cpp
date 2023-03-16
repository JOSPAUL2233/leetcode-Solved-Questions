class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
//         map<int,int> m;
//         vector<int> ans;
        
//         //storing the frequencies of elements
//         for(int i = 0;i<nums.size();i++){

//             m[nums[i]]++;
            
          
//         }
        
//         //checking the count
//         for(auto it : m){
            
//             if(it.second == 2)ans.push_back(it.first);
            
//         }
        
//         return ans;
        
        
         if(nums.empty())return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
        
    }
};