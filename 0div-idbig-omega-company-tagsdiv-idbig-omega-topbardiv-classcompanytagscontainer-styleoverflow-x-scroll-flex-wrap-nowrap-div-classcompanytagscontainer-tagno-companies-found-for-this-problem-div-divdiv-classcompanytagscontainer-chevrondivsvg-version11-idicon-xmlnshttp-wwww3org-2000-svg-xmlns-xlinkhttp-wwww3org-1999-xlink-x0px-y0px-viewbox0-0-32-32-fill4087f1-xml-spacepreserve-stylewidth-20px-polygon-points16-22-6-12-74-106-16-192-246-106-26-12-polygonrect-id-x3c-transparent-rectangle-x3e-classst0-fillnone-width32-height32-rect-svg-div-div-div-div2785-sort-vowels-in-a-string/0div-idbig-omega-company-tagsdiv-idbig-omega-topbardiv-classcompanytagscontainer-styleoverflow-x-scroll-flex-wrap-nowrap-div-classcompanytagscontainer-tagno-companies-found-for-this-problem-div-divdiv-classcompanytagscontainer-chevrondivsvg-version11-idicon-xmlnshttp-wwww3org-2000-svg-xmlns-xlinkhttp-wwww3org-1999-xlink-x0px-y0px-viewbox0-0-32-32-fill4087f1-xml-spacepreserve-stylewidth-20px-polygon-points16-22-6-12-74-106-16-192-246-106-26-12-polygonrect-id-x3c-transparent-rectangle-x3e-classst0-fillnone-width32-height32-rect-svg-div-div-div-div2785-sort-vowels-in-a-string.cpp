class Solution {
public:
    
    bool isVowel(char c){
        
        if(c == 'A' || c == 'a' || c == 'e' || c == 'E' || c == 'I' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            return true;
        else
            return false;
        
    }
    
    string sortVowels(string s) {
        
        //maintain a freq map of all the vowels
        
        unordered_map<char,int> freq;
        
        for(char c  : s)
            freq[c]++;
        
        //now, keep them in sorted order
        string vowelOrder = "AEIOUaeiou";
        int index = 0;
        
        //now, follow the count sort method
        
        for(int i = 0;i<s.size();i++){
            
            if(isVowel(s[i])){
                
                while(freq[vowelOrder[index]] == 0)
                    index++;
                
                s[i] = vowelOrder[index];//assiin the vowel
                freq[vowelOrder[index]]--;//decreaset the frequency
                
            }
            
        }

        return s;
    }
};