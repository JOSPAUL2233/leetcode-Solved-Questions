class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        if(nums.size()==1)return 0;
        
        vector<long long> prefixSum(nums.size(),0);
        vector<long long> postfixSum(nums.size(),0);
        
        long long sum = 0;
        
        //put prefixSum
        for(int i = 0;i<nums.size();i++){
            
            sum += (long long)nums[i];
            prefixSum[i] = sum;
            
        }
        
        sum = 0;
        
        //put postfixSum
        for(int i = nums.size()-1;i>=0;i--){
            
            sum+= (long long)nums[i];
            postfixSum[i] = sum;
            
        }
        
        //solve it using prefixSum and postfixSum
        
        for(int i = 0;i<nums.size();i++){
            
            
            if(i==0){//first element
                
                if(postfixSum[i+1]==0)
                        return i;
                
            }
            else if(i==nums.size()-1){//last element
                
                if(prefixSum[i-1]==0)
                    return i;
                
            }
            
            else{//rest of the elements
                
                if(prefixSum[i-1] == postfixSum[i+1])return i;
                
            }
        }
        
        return -1;
        
    }
};