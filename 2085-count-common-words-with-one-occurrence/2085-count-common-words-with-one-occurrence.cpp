class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        int count = 0;
        unordered_map<string,int> freq;
        
        for(int i = 0;i<words1.size();i++){
            
            
            for(int j = 0;j<words2.size();j++){
                
                    if(words1[i]==words2[j]){
                        
                        freq[words1[i]]++;
                        
                    }
                
            }
            
            
        }
        
        for(int i = 0;i<words1.size();i++){
            
            if(freq[words1[i]]==1)count++;
            
        }
        
        return count;
        
    }
};