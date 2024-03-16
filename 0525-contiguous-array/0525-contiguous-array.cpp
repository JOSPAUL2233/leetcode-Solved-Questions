class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int sum = 0;
        
        map<int,int> prefix;//sum,index
        prefix[0] = -1;
        
        int maxi = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            sum += nums[i]==1 ? 1 :-1;
            
            if(prefix.find(sum)!=prefix.end()){
                
                int len = i - prefix[sum];
                
                maxi = max(maxi,len);
                
            }else{
                
                prefix[sum] = i;
                
            }
            
            
        }
        
        return maxi;
        
    }
};