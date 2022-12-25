class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> ans;
        
        int sum = 0;
        
        //finding the xor of all the elements in the vector
        
        for(int i = 0;i<nums.size();i++){
            
            sum^=nums[i];
            
        }
        
        // finding the 1st bit in sum which is 1 (we can take other bit                also which is 1)
        
        int index = 0;
        
        for(int i = 0;i<31;i++){
            
            if(sum>>i & 1){
                index = i;
                break;
            }
            
        }
        
        //seperating the elements on the basis of the bit found in the 2nd          loop(1s in one group and 0s in another group) and do xor them.
        
        int ones = 0;
        int zeroes = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i]>>index & 1){
                
                ones^=nums[i];
                
            }
            else{
                zeroes^=nums[i];
            }
            
        }
        
        ans.push_back(ones);
        ans.push_back(zeroes);
        
        return ans;
        
    }
};