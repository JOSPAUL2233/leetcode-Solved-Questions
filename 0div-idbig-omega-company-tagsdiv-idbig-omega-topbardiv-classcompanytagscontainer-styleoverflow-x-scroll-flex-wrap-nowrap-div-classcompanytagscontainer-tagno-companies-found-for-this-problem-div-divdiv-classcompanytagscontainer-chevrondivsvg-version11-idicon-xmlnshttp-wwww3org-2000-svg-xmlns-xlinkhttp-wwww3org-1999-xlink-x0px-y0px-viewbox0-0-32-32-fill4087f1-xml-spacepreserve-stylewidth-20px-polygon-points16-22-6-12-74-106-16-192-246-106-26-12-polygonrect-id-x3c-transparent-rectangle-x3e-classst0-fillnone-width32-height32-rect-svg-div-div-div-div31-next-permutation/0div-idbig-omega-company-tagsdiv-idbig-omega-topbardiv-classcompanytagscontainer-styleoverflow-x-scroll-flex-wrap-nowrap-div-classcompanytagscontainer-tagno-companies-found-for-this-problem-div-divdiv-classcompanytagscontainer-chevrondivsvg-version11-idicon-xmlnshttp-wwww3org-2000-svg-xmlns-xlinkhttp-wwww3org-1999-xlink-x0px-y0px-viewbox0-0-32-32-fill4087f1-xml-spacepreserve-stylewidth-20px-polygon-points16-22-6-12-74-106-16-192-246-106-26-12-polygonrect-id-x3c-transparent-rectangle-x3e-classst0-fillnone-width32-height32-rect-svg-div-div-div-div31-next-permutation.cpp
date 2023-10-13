class Solution {
public:
    
    void reverse(vector<int> &nums,int left,int right){
        
        while(left<right){
            
            swap(nums[left],nums[right]);
            left++;
            right--;
            
        }
        
    }
    
    void nextPermutation(vector<int>& nums) {
        
        //find the breaking point
        int index = -1;
        
        for(int i = nums.size()-2;i>=0;i--)
            if(nums[i] < nums[i+1]){
                
                index = i;
                break;
                
            }
        
        if(index == -1)
            reverse(nums,0,nums.size()-1);
        else{
            //find just greater element after braking point
            int greater = -1;
            for(int i = nums.size()-1;i>index;i--){

                if(nums[i] > nums[index]){

                    greater = i;
                    break;

                }

            }   
                //swap
                swap(nums[greater],nums[index]);
                
                //sort the right side
                reverse(nums,index+1,nums.size()-1);
                        
        }
    }
};