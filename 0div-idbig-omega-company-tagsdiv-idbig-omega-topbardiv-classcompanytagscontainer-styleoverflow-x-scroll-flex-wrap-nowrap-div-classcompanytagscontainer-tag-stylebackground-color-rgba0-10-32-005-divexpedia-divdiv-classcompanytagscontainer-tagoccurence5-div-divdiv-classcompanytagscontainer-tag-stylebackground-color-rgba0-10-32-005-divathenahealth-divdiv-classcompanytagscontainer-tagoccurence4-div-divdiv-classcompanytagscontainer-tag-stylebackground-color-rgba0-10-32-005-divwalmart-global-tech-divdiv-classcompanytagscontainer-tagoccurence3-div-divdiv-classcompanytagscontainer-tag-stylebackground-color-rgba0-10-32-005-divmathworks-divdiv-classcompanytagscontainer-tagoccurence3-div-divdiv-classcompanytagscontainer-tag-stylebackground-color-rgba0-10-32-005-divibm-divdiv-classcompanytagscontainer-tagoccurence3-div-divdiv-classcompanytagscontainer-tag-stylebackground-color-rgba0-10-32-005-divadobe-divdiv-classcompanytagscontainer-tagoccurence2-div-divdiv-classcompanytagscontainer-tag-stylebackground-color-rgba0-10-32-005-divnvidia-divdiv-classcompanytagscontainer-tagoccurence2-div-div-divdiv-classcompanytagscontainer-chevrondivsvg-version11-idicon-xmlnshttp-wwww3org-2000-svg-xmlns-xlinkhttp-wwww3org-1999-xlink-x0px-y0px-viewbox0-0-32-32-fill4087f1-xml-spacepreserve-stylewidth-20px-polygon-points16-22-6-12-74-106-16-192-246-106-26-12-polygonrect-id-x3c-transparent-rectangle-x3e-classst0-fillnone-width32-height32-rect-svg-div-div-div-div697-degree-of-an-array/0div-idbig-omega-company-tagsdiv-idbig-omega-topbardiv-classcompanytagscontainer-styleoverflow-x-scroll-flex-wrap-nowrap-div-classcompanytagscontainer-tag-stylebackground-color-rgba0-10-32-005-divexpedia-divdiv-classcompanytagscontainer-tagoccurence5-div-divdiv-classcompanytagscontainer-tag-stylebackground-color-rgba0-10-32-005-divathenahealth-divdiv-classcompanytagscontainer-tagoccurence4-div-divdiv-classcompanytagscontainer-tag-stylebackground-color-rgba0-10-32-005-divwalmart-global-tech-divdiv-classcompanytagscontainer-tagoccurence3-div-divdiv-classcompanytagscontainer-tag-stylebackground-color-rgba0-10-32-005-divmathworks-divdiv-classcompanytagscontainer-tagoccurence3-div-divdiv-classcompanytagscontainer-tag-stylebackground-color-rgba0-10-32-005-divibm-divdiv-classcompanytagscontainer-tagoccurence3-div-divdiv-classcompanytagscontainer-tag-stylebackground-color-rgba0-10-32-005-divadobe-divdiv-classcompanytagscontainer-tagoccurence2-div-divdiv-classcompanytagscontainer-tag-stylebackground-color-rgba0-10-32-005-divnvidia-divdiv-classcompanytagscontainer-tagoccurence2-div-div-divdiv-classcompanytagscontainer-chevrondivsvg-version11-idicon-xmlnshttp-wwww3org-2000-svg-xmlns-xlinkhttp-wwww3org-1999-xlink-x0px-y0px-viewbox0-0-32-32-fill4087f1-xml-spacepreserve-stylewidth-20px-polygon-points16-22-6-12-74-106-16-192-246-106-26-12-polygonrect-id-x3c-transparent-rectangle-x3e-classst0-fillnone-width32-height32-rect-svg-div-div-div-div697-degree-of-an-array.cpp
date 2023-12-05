class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        map<int,int> freq;
        map<int,int> first;
        map<int,int> last;
        
        int minLen = INT_MAX;
        
        int maxi = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            //increase the frequecy
            freq[nums[i]]++;
            
            //update first and last occurance of the element
            if(first.find(nums[i]) == first.end()){
                first[nums[i]] = i;
            }
            
            last[nums[i]] = i;
            
            //update the maximum frequency
            if(freq[nums[i]] > maxi){
                maxi = freq[nums[i]];
            }            
            
        }
        
                
        for(int i = 0;i<nums.size();i++){
            
            if(freq[nums[i]] == maxi){
                
                int len = last[nums[i]] - first[nums[i]] + 1;
                
                minLen = min(minLen , len);
                
            }
            
        }
        
        return minLen;
        
    }
};