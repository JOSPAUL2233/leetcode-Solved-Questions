class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int countOne = 0;
        int countZero = 0;
        int countTwo = 0;
        
        //counting the number of one's,two's and zero's
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i] == 0)
                countZero++;
            else if(nums[i]==1)
                countOne++;
            else if(nums[i] == 2)
                countTwo++;
            
        }
        
        //overriding the existing values in sorted order
        
        for(int i = 0;i<nums.size();i++){
            
            if(countZero){
                nums[i] = 0;
                countZero--;
            }else if(countOne){
                nums[i] = 1;
                countOne--;
            }
            else if(countTwo){
                nums[i] = 2;
                countTwo--;
            }
                
        }
        
    }
};