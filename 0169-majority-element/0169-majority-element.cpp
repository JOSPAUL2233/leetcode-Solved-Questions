class Solution {
public:
    int majorityElement(vector<int>& nums) {
            
        
        int element = -1;
        int count = 0;
        
        //find the possible majority element
        for(int i = 0;i<nums.size();i++){
            
            //if count is found to be zero, change the element and start counting from here
            //for this element
            if(count <= 0){
                
                element = nums[i];
                count = 1;
                
            }else if(nums[i] == element){
                count++;
            }else if(nums[i] != element){
                count--;
            }
            
        }
        
        //now, check if the majority element exists by
        //checking the number of times the majority element appears in the array
        count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == element)
                count++;
        }
        
        if(count > nums.size()/2)
            return element;
        else
            return -1;
    }
};