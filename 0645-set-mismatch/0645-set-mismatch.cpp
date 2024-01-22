class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        map<int,int> freq;
        int m,r;
        
        for(int i = 0;i<nums.size();i++)
            freq[nums[i]]++;
        
        for(int i = 0;i<nums.size();i++){
            
            if(freq[i+1] == 2)r = i+1;
            
            if(freq[i+1] == 0)m = i+1;
            
        }
        
        return {r,m};
        
    }
};