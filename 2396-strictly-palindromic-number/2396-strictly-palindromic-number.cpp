class Solution {
public:
    bool isStrictlyPalindromic(int n) {
                
        int base = 2;
        string binary = "";
        
        while(base <= n-2){
            
            
            binary = "";
            int digit = n;
            
            while(digit){
                
                int rem = digit % base;
                
                digit /= base;
                
                binary += (to_string(rem));
                
            }
            
            //check whether it is palindrome
            
            for(int i = 0;i<binary.size()/2;i++){
                
                if(binary[i] != binary[binary.size()-1-i])return false;
                
            }
            
            base++;
        
        }
        
        return true;
         
    }
};