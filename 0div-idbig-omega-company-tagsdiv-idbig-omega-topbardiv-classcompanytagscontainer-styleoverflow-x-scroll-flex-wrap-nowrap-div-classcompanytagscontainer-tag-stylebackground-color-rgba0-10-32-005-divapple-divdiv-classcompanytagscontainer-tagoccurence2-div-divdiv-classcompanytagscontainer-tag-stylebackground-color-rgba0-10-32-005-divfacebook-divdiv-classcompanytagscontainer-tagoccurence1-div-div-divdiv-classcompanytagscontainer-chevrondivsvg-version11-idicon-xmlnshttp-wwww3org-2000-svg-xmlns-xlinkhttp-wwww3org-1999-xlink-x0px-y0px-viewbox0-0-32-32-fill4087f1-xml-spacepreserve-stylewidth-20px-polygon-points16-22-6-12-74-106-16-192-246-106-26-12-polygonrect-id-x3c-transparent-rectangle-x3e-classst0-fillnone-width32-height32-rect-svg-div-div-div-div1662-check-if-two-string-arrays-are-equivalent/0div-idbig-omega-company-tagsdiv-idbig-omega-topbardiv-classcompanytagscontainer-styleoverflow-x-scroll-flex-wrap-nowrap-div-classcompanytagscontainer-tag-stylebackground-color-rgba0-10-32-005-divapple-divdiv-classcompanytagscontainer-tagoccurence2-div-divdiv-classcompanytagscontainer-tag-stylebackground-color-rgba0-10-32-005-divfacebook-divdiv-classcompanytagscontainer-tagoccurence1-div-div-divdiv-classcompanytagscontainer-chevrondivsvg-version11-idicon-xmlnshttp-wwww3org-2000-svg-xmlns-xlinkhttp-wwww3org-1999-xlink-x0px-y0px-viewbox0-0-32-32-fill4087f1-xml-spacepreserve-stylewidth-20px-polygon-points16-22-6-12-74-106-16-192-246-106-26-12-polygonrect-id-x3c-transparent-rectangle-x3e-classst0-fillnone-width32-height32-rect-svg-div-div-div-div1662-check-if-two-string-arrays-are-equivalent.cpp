class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int s1 = 0;
        int s2 = 0;
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        while(s1<word1.size() && s2<word2.size()){
                        
            //if not equal
            if(word1[s1][ptr1++] != word2[s2][ptr2++])
                return false;
            
            
            //update to next string if needed 
            
            if(ptr1 == word1[s1].size()){
                
                ptr1 = 0;
                s1++;
                
            }
            
            if(ptr2 == word2[s2].size()){
                
                ptr2 = 0;
                s2++;
                
            }            
            
        }
        
        return (s1==word1.size()) && (s2==word2.size());
        
    }
};