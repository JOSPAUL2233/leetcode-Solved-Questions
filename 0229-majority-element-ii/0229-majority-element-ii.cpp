class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        //there will be at most 2 elements which can appear n/3 times
        
        //let's keep seperate counter for those two elements
        int count1 = 0;
        int count2 = 0;
        
        //taking an elements which cannot be in the array
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        
        //iterate throughout the vector
        for(int i = 0;i<nums.size();i++){
            
            //here are the conditions(algorithm)
            
            if(count1 == 0 && nums[i] != ele2){
                
                count1 = 1;
                ele1 = nums[i];
                
            }else if(count2 == 0 && nums[i] != ele1){
                
                count2 = 1;
                ele2 = nums[i];
                
            }else if(nums[i] == ele1){
                
                count1++;
                
            }else if(nums[i] == ele2){
                
                count2++;
                
            }else{
                
                count1--;
                count2--;
                
            }
            
            
        }
        
        //possible anwers are in ele1 and ele2, now check manually whether
        //they are the majority elements(more than n/3 occurances)
        
        count1 = 0;
        count2 = 0;
        
        //stores the answer
        vector<int> ans;
        
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i] == ele1)
                count1++;
            
            if(nums[i] == ele2)
                count2++;

        }
        
        //place the elements if they are majority
        
        if(count1 > nums.size()/3)
                ans.push_back(ele1);
            
        if(count2 > nums.size()/3)
                ans.push_back(ele2);
        
        
        return ans;
        
    }
};