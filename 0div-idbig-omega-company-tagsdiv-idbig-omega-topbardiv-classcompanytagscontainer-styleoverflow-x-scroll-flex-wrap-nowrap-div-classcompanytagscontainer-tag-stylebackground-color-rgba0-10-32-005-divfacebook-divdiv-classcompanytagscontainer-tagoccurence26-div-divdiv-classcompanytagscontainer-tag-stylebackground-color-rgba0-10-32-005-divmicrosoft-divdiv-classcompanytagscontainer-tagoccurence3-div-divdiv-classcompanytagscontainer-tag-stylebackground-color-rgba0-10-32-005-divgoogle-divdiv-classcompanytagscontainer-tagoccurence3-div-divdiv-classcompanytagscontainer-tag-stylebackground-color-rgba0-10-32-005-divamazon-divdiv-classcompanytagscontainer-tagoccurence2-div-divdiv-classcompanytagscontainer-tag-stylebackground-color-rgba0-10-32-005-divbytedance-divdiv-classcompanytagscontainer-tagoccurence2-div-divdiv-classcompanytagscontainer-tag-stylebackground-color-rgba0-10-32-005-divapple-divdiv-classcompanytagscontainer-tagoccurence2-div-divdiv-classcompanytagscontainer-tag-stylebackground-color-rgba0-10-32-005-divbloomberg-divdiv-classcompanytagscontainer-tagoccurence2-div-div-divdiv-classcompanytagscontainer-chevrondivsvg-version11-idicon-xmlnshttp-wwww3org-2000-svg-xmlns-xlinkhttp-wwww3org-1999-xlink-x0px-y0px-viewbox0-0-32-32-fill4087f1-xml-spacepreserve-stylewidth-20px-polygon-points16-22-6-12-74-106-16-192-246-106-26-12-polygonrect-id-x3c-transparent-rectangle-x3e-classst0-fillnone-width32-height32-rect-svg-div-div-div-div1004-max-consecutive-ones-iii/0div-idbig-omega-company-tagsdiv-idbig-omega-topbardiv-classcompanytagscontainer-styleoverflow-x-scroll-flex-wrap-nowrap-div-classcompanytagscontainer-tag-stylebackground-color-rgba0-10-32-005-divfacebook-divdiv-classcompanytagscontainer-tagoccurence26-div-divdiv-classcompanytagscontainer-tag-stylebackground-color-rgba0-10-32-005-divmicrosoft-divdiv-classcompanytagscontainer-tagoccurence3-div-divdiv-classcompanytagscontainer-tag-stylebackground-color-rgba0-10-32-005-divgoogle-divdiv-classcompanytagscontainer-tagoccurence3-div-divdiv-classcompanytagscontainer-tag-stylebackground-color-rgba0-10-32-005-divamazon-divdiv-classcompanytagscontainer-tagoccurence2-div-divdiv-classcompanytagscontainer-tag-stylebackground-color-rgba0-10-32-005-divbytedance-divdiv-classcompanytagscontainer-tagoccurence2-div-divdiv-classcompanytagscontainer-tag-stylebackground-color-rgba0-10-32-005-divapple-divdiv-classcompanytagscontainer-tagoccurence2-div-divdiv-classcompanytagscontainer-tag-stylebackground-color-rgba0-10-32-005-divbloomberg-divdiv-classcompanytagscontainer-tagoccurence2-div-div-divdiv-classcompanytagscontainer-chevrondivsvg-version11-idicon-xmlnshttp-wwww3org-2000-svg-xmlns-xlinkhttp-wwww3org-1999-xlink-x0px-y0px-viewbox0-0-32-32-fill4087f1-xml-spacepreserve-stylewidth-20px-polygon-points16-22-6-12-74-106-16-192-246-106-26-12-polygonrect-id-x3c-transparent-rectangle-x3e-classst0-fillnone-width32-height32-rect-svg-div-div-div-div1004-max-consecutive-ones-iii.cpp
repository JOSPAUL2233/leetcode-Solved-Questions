class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int count = 0;
        int maxCount = INT_MIN;
        
        int left = 0;
        int maxSwap = k;
        
        for(int right = 0;right<nums.size();right++){
            
            if(nums[right] == 1 || k>0){
                
                if(nums[right] == 0)
                    k--;
                
            }else{
                
                while(left <= right && k == 0){
                    
                    if(nums[left] == 0)
                        k++;
                    
                    left++;
                    
                }
                
                if(nums[right] == 0)
                    k--;
                
            }
            
            cout<<left<<" "<<right<<endl;
            cout<<"k:"<<k<<endl;
            
            int count = right - left + 1;
        
            maxCount = max(maxCount,count);
            
        }
        
        return maxCount;
        
    }
};