class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        
        for(int i = 2;i<nums.size();i++){
            
            //two pointers
            int left = 0;
            int right = i-1;
            
            while(left < right){
                
                //define side lengths
                int a = nums[left];
                int b = nums[right];
                int c = nums[i];
                
                //check if they can be sides of a triangle
                if((a+b) > c){
                    ans = ans + (right - left);
                    right--;
                }else{
                    
                    left++;
                    
                }
                
            }
            
        }
        return ans;
    }
};