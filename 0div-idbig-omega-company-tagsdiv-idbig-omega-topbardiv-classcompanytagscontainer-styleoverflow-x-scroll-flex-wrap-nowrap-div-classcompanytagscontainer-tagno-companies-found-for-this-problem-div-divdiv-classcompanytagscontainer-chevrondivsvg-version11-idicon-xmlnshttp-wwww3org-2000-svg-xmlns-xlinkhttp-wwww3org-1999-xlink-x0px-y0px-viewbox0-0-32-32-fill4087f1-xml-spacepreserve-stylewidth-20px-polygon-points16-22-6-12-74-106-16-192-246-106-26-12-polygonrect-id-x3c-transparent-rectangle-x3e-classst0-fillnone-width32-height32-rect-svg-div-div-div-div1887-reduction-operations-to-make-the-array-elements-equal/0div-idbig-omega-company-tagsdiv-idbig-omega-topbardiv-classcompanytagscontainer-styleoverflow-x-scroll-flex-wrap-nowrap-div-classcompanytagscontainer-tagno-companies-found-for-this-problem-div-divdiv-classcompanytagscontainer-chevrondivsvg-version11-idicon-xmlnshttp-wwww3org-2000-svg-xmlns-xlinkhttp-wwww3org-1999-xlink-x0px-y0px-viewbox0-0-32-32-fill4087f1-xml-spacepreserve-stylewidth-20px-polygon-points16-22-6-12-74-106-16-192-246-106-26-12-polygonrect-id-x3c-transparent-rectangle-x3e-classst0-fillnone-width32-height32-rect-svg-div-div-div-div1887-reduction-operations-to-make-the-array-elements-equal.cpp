class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int largest = nums.size()-1;
        
        int ans = 0;
        
        while(largest >= 0){
            
            int largestEle = nums[largest];
            
            while(largest >= 0 && nums[largest] == largestEle){
                largest--;
            }
            
            int count = nums.size() -1 - largest;
            
            if(largest < 0)
                break;
            else
                ans += count;
            
            
        }
        
        return ans;
        
    }
};