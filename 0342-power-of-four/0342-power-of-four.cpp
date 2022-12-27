class Solution {
public:
    bool isPowerOfFour(int n) {
        
        int count = 0;
        
        for(int i = 0;i<32;i=i+2){
            
            if((n>>i)&1)count++;
            if((n>>i+1)&1)return false;
            
        }
        
        if(count==1)return true;
        else return false;
        
    }
};