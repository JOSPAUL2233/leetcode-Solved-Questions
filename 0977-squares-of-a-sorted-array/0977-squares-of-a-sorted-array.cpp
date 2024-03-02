class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> sq(nums.size(),0);
        int ptr = nums.size()-1;
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right){
            
            if(abs(nums[left]) > abs(nums[right])){
                sq[ptr--] = nums[left]*nums[left];
                left++;
            }else{
                sq[ptr--] = nums[right]*nums[right];
                right--;
            }
        }
        
        return sq;
        
    }
};