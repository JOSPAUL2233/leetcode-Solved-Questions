class Solution {
public:
    
    bool isVowel(char c){
        
        if(c == 'A' || c == 'a' || c == 'e' || c == 'E' || c == 'I' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
            return true;
        else
            return false;
        
    }
    
    string sortVowels(string s) {
        
        //extract the vowels and keep it in a string
        string vowel = "";
        
        for(int i = 0;i<s.size();i++){
            
            if(isVowel(s[i]))
                vowel.push_back(s[i]);
            
        }
        
        sort(vowel.begin(),vowel.end());
        
        int index = 0;
        
        for(int i = 0;i<s.size();i++){
            
            if(isVowel(s[i]))
                s[i] = vowel[index++];
            
        }
        
        return s;
        
    }
};