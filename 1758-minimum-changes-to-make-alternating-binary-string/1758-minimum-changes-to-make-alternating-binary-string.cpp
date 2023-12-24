class Solution {
public:
    
    void change(char &c){
        
        if(c == '1')
            c = '0';
        else
            c = '1';
        
    }
    
    int minOperations(string s) {
        
        char c1 = '0';
        char c2 = '1';
        
        int count1 = 0;
        int count2 = 0;
        
        for(int i = 0;i<s.size();i++){
            
            if(s[i] != c1)
                count1++;
            
            if(s[i] != c2)
                count2++;
            
            change(c1);
            change(c2);
            
        }
        
        return min(count1,count2);
        
    }
};