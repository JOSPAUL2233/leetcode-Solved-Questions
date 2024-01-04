class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        //store the frequecy 
        map<int,int> freq;
        
        for(int i : nums)
            freq[i]++;
        
        int count = 0;
        
        for(auto i : freq){
            
            if(i.second == 1)
                return -1;
            
            count += (i.second/3);
            
            if(i.second%3 != 0)
                count++;
            
        }
        
        return count;
        
    }
};