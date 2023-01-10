class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int Negatives = 0;
        int Positives = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            if(nums[i]<0)Negatives++;
            
            else if(nums[i]==0)continue;
            
            else {
                Positives = nums.size() - i;
                break;
            }
            
        }
        
        return(Negatives>Positives?Negatives:Positives);
        
    }
};