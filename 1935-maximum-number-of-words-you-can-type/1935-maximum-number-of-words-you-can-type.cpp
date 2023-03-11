class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        //creating an unordered_map
        
        unordered_map<char,int> m;
        
        for(int i = 0;i<brokenLetters.size();i++){
            
            m[brokenLetters[i]] = 1;
            
        }
        
        //check whether the words are in map or not
        
        int count = 0;
        
        string s;
        
        for(int i = 0;i<text.size();i++){
            
            if(text[i]==' ' || i == text.size()-1){
                
                if(i==text.size()-1){
                    s.push_back(text[i]);
                }
                
                //check if all the letters are possible to type
                bool flag = false;
                
                for(int i = 0;i<s.size();i++){
                    
                    if(m.count(s[i]) > 0){
                        flag = true;
                        break;
                    }
                    
                }
                
                if(!flag)count++;
                
                s.clear();
                
            }else{
                
                s.push_back(text[i]);
                
            }
            
        }
        
        return count;
        
    }
};