class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        
        int n = possible.size();
        
        vector<int> prefix(possible.size(),0);
        vector<int> suffix(possible.size(),0);
        
        int pre = 0;
        int suf = 0;
        
        for(int i = 0;i<n;i++){
            
            if(possible[i]==1)
                pre++;
            else
                pre--;
            
            if(possible[n-1-i]==1)
                suf++;
            else
                suf--;
            
            prefix[i] = pre;
            suffix[n-1-i] = suf;
        }
        
        //iterate
        
        for(int i = 0;i<n-1;i++){
            
            if(prefix[i] > suffix[i+1])
                return i+1;
            
        }
        
        return -1;        
        
    }
};