class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
        //place the left pointer to the 1st position of zero
        int left = -1;
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i]==0){
                left = i;
                break;
            }
        
        }
        
        //if there are no zeroes
        if(left == -1)
            return;
            
        //move the pointer left and right and swap accordingly
        
        for(int right = left + 1;right < nums.size();right++){
            
            if(nums[right] != 0){
                
                swap(nums[left],nums[right]);
                left++;
                
            }
            
        }
        
    }
};