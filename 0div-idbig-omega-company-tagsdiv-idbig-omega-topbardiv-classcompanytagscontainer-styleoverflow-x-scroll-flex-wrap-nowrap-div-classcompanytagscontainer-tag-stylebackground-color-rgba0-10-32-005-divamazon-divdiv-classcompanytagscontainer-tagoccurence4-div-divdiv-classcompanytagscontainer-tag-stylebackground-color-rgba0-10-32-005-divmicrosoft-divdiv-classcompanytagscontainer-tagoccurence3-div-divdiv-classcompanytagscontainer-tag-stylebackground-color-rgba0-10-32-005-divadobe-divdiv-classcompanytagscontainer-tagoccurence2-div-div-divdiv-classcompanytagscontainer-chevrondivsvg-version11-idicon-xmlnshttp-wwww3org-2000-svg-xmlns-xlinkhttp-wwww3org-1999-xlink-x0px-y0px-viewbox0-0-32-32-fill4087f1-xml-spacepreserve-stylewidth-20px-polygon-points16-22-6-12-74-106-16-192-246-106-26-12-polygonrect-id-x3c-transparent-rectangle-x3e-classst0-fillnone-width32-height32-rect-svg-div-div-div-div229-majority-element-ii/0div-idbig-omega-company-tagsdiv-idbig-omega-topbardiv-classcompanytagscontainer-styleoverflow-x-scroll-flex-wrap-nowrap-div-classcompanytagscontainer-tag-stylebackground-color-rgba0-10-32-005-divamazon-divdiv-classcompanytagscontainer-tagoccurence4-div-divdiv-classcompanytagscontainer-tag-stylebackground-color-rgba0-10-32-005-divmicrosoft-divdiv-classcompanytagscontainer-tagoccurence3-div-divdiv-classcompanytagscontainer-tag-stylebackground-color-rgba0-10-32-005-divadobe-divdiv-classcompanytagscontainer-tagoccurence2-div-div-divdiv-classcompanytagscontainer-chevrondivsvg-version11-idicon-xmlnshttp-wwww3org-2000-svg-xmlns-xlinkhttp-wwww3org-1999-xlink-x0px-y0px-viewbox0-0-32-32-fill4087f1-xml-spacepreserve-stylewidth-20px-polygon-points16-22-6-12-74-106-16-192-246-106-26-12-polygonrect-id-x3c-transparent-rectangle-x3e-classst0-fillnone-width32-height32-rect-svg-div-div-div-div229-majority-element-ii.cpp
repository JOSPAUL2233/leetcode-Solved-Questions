class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        
        int ele1 = INT_MIN;
        int count1 = 0;
        int ele2 = INT_MIN;
        int count2 = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(count1 == 0 && nums[i] != ele2){
                
                ele1 = nums[i];
                count1 = 1;
                
            }else if(count2 == 0 && nums[i] != ele1){
                
                ele2 = nums[i];
                count2 = 1;
                
            }else if(ele1 == nums[i]){
                
                count1++;
                
            }else if(ele2 == nums[i]){
                
                count2++;
                
            }else{
                
                count1--;
                count2--;
                
            }
            
        }
        
        //potential candidate, so we should check that
        count1 = 0;
        count2 = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(ele1 == nums[i])
                count1++;
            
            if(ele2 == nums[i])
                count2++;
            
        }
        
        vector<int> ans;
        if(count1 > nums.size()/3)
            ans.push_back(ele1);
        
        if(count2 > nums.size()/3)
            ans.push_back(ele2);
        
        return ans;
        
    }
};