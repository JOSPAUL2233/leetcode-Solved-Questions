class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int maxi = 0;
        unordered_map<int,int> freq;
        
        for(int i : nums){
            freq[i]++;
            maxi = max(maxi,freq[i]);
        }
        
        int count = 0;
        
        for(int i : nums){
            if(freq[i] == maxi)
                count++;
        }
        
        return count;
        
    }
};