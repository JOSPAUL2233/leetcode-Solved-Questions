class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> freq;
        map<int,int> freq1;
        
        for(int i : arr)
            freq[i]++;
        
        for(auto p : freq){
            
            freq1[p.second]++;
            
            if(freq1[p.second] > 1)
                return false;
            
        }
        
        return true;
        
    }
};